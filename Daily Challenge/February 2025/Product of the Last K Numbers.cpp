class ProductOfNumbers {
private:
  long long product = 1;
  vector<long long> prefix = {1};
public:
  ProductOfNumbers() {
    
  }
  
  void add(int num) {
    if (num == 0) {
      prefix = {1};
      product = 1;
    } else {
      product *= num;
      prefix.push_back(product);
    }
  }
  
  int getProduct(int k) {
    if (k >= prefix.size()) {
      return 0;
    }
    
    return prefix.back() / prefix[prefix.size() - k - 1];
  }
};
  
  /**
   * Your ProductOfNumbers object will be instantiated and called as such:
   * ProductOfNumbers* obj = new ProductOfNumbers();
   * obj->add(num);
   * int param_2 = obj->getProduct(k);
   */