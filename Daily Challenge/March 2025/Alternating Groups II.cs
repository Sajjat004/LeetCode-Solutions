public class Solution {
  public int NumberOfAlternatingGroups(int[] colors, int k) {
    int n = colors.Length;
    List<int> newColors = new List<int>();
    foreach (int color in colors) {
      newColors.Add(color);
    }
    foreach (int color in colors) {
      newColors.Add(color);
    }

    colors = newColors.ToArray();
    int left = 0, groups = 0;

    for (int i = 1; i < n + k - 1; ++i) {
      if (colors[i] == colors[i - 1]) {
        if (i - left >= k) groups += (i - left - k + 1);
        left = i;
      }
    }

    if (n + k - 1 - left >= k) groups += (n + k - 1 - left - k + 1);
    
    return groups;
  }
}