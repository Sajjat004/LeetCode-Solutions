class Solution {
public:
  int numTilePossibilities(string tiles) {
    unordered_set<string> sequences;
    vector<bool> used(tiles.size(), false);

    string current = "";
    generateSequences(tiles, used, sequences, current);

    return sequences.size() - 1;
  }

private:
  void generateSequences(string& tiles, vector<bool>& used, unordered_set<string>& sequences, string& current) {
    
    sequences.insert(current);

    for (int i = 0; i < tiles.size(); ++i) {
      if (used[i]) {
        continue;
      }

      used[i] = true;
      current.push_back(tiles[i]);
      generateSequences(tiles, used, sequences, current);
      current.pop_back();
      used[i] = false;
    }
  }
};