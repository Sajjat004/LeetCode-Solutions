class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    map<string, bool> taken;
    vector<string> res;
    for (const string& f : folder) {
      string path = "";
      bool isSubfolder = false;
      int i = 0;
      while (i < f.size()) {
        path += f[i++];
        while (i < f.size() && f[i] != '/') {
          path += f[i++];
        }
        if (taken[path]) {
          isSubfolder = true;
          break;
        }
      }
      if (!isSubfolder) {
        res.push_back(f);
        taken[path] = true;
      }
    }

    return res;
  }
};