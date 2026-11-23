#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
 private:
  vector<int32_t> products_;
  int last_zero = -1;

 public:
  ProductOfNumbers() { products_ = {1}; }

  void add(int num) {
    if (num > 0) {
      products_.push_back(products_.back() * num);
    } else {
      products_.push_back(1);
      last_zero = products_.size() - 1;
    }
  }

  int getProduct(int k) {
    int start_id = products_.size() - k;
    if (start_id <= last_zero) {
      return 0;
    }
    return products_.back() / (start_id == 0 ? 1 : products_[start_id - 1]);
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main() { return 0; }