public class Solution {
  public int NumTilePossibilities(string tiles) {
    HashSet<string> sequences = new HashSet<string>();
    bool[] used = new bool[tiles.Length];

    GenerateSequnces(tiles, used, "", sequences);

    return sequences.Count - 1;
  }

  private void GenerateSequnces(string tiles, bool[] used, string current, HashSet<string> sequences) {
    sequences.Add(current);

    for (int i = 0; i < tiles.Length; i++) {
      if (used[i]) continue;

      used[i] = true;
      GenerateSequnces(tiles, used, current + tiles[i], sequences);
      used[i] = false;
    }
  }
}