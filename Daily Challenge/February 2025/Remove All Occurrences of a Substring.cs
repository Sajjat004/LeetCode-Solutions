public class Solution {
  public string RemoveOccurrences(string s, string part) {
    int sLength = s.Length;
    int partLength = part.Length;
    Stack<char> characterStack = new Stack<char>();

    foreach (char x in s) {
      characterStack.Push(x);

      if (characterStack.Count >= partLength && StackContainsPart(characterStack, ref part)) {
        for (int i = 0; i < partLength; ++i) {
          characterStack.Pop();
        }
      }
    }

    string result = "";
    while (characterStack.Count > 0) {
      result = characterStack.Pop() + result;
    }

    return result;
  }

  private bool StackContainsPart(Stack<char> characterStack, ref string part) {
    Stack<char> tempStack = new Stack<char>();
    
    for (int i = part.Length - 1; i >= 0; --i) {
      if (characterStack.Peek() != part[i]) {
        while (tempStack.Count > 0) {
          characterStack.Push(tempStack.Pop());
        }

        return false;
      }

      tempStack.Push(characterStack.Pop());
    }

    while (tempStack.Count > 0) {
      characterStack.Push(tempStack.Pop());
    }

    return true;
  }
}