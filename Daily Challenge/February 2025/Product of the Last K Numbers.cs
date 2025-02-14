public class ProductOfNumbers {

  private List<int> products;

  public ProductOfNumbers() {
    products = new List<int>();
    products.Add(1);
  }
  
  public void Add(int num) {
    if (num == 0) {
      products = new List<int>();
      products.Add(1);
    } else {
      products.Add(products.Last() * num);
    }
  }
  
  public int GetProduct(int k) {
    if (k >= products.Count) {
      return 0;
    }
    return products.Last() / products[products.Count - k - 1];
  }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.Add(num);
 * int param_2 = obj.GetProduct(k);
 */