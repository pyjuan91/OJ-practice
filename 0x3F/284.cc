#include <bits/stdc++.h>
using namespace std;

class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    has_cached_ = false;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (not has_cached_) {
      int val = Iterator::next();
      has_cached_ = true;
      cache_ = val;
    }
    return cache_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (has_cached_) {
      has_cached_ = false;
      return cache_;
    }
    return Iterator::next();
  }

  bool hasNext() const { return has_cached_ or Iterator::hasNext(); }

 private:
  int cache_;
  bool has_cached_;
};