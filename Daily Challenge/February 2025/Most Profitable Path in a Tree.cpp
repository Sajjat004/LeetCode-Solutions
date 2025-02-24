class Solution {
  public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
      int n = amount.size();
      vector<vector<int>> adj(n);

      for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }

      vector<vector<int>> adjOfLeafToRoot(n);
      dfs(0, -1, adj, adjOfLeafToRoot);
      vector<int> bobReachTime(n, -1);
      bobReachTime[bob] = 0;
      dfs2(bob, adjOfLeafToRoot, bobReachTime);

      int maxAmount = INT_MIN;
      dfs3(0, -1, 0, adj, amount, bobReachTime, 0, maxAmount);

      return maxAmount;
    }

  private:
    void dfs(int node, int par, vector<vector<int>>& adj, vector<vector<int>>& adjOfLeafToRoot) {
      for (int child : adj[node]) {
        if (child == par) {
          continue;
        }

        adjOfLeafToRoot[child].push_back(node);
        dfs(child, node, adj, adjOfLeafToRoot);
      }
    }

    void dfs2(int node, vector<vector<int>>& adjOfLeafToRoot, vector<int>& bobReachTime) {
      for (int child : adjOfLeafToRoot[node]) {
        bobReachTime[child] = bobReachTime[node] + 1;
        dfs2(child, adjOfLeafToRoot, bobReachTime);
      }
    }

    void dfs3(int node, int par, int sum, vector<vector<int>>& adj, vector<int>& amount, vector<int>& bobReachTime, int aliceReachTime, int& maxAmount) {
      if (bobReachTime[node] == -1) sum += amount[node];
      else if (bobReachTime[node] > aliceReachTime) sum += amount[node];
      else if (bobReachTime[node] == aliceReachTime) sum += amount[node] / 2;

      bool isLeaf = true;

      for (int child : adj[node]) {
        if (child == par) {
          continue;
        }
        isLeaf = false;
        dfs3(child, node, sum, adj, amount, bobReachTime, aliceReachTime + 1, maxAmount);
      }

      if (isLeaf) {
        maxAmount = max(maxAmount, sum);
      }
    }
  };