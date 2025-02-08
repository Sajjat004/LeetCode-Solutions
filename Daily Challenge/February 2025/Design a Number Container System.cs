public class NumberContainers {

  private Dictionary<int, int> _indexToNumber;
  private Dictionary<int, PriorityQueue<int, int>> _numberToIndex;

  public NumberContainers() {
    _indexToNumber = new Dictionary<int, int>();
    _numberToIndex = new Dictionary<int, PriorityQueue<int, int>>();
  }
  
  public void Change(int index, int number) {
    if (_indexToNumber.ContainsKey(index)) {
      _indexToNumber[index] = number;
    } else {
      _indexToNumber.Add(index, number);
    }

    if (!_numberToIndex.ContainsKey(number)) {
      var pq = new PriorityQueue<int, int>();
      _numberToIndex.Add(number, pq);
    }

    _numberToIndex[number].Enqueue(index, index);
  }
  
  public int Find(int number) {
    while (_numberToIndex.ContainsKey(number) && _numberToIndex[number].Count > 0) {
      int index = _numberToIndex[number].Peek();
      if (number == _indexToNumber[index]) return index;
      _numberToIndex[number].Dequeue();
    }

    return -1;
  }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.Change(index,number);
 * int param_2 = obj.Find(number);
 */