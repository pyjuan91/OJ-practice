#include <bits/stdc++.h>
using namespace std;

class HashedSequence {
  // item's range is [0, 50]
 private:
  static const int64_t M = (1LL << 61) - 1;
  static const int64_t B;
  static vector<int64_t> pow;
  vector<int64_t> p_hash;
  __int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
  int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % M; }

 public:
  HashedSequence(const vector<int>& s) : p_hash(s.size() + 1) {
    while (pow.size() < s.size()) {
      pow.push_back(mod_mul(pow.back(), B));
    }
    p_hash[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
    }
  }

  int64_t get_hash(int start, int end) {
    int64_t raw_val =
        p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
    return (raw_val + M) % M;
  }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<int64_t> HashedSequence::pow = {1};
const int64_t HashedSequence::B =
    uniform_int_distribution<int64_t>(0, M - 1)(rng);

class Solution {
 public:
  int beautifulSplits(vector<int>& nums) {
    int n = nums.size();
    auto hs = HashedSequence(nums);
    int ans = 0;
    for (int nums2_start = 1; nums2_start < n - 1; nums2_start++) {
      for (int nums3_start = nums2_start + 1; nums3_start < n; nums3_start++) {
        int nums1_start = 0;
        int nums1_end = nums2_start - 1;
        int nums1_len = nums1_end - nums1_start + 1;
        int nums2_end = nums3_start - 1;
        int nums2_len = nums2_end - nums2_start + 1;
        int nums3_end = n - 1;
        int nums3_len = nums3_end - nums3_start + 1;
        bool is_nums1_prefix_of_nums2 =
            nums1_len <= nums2_len
                ? hs.get_hash(nums1_start, nums1_end) ==
                      hs.get_hash(nums2_start, nums2_start + nums1_len - 1)
                : false;
        bool is_nums2_prefix_of_nums3 =
            nums2_len <= nums3_len
                ? hs.get_hash(nums2_start, nums2_end) ==
                      hs.get_hash(nums3_start, nums3_start + nums2_len - 1)
                : false;
        if (is_nums1_prefix_of_nums2 or is_nums2_prefix_of_nums3) ans++;
      }
    }
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  Solution s;
  cout << s.beautifulSplits(nums) << endl;
  return 0;
}