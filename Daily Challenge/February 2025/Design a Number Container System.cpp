class NumberContainers {
  private:
  unordered_map<int, int> IndexToNumber;
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> NumberToIndex;

  public:
    NumberContainers() {
      IndexToNumber.clear();
      NumberToIndex.clear();
    }
    
    void change(int index, int number) {
      IndexToNumber[index] = number;
      NumberToIndex[number].push(index);
    }
    
    int find(int number) {
      while (!NumberToIndex[number].empty()) {
        int index = NumberToIndex[number].top();
        if (number == IndexToNumber[index]) return index;
        NumberToIndex[number].pop();
      }

      return -1;
    }
  };
  
/**
  * Your NumberContainers object will be instantiated and called as such:
  * NumberContainers* obj = new NumberContainers();
  * obj->change(index,number);
  * int param_2 = obj->find(number);
  */