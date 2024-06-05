#include <bits/stdc++.h>

class BigInteger {
 private:
  std::vector<int> digits;
  bool is_negative;

 public:
  BigInteger() : is_negative(false) {}
  BigInteger(long long num) {
    is_negative = num < 0;
    num = std::abs(num);
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }
    if (digits.empty()) digits.push_back(0);
  }
  BigInteger(const std::string& str) {
    // notice -0 should be treated as 0
    if (str.size() > 1 and str[0] == '-' and str[1] != '0') {
      is_negative = true;
    }
    for (int i = str.size() - 1; i >= 0; --i) {
      if (isdigit(str[i])) {
        digits.push_back(str[i] - '0');
      }
    }
    if (digits.empty()) digits.push_back(0);
  }
  // support comparison
  bool operator==(const BigInteger& other) const {
    return is_negative == other.is_negative && digits == other.digits;
  }
  bool operator!=(const BigInteger& other) const { return !(*this == other); }
  bool operator<(const BigInteger& other) const {
    if (is_negative != other.is_negative) {
      return is_negative;
    }
    if (digits.size() != other.digits.size()) {
      return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i] != other.digits[i]) {
        return digits[i] < other.digits[i];
      }
    }
    return false;
  }
  bool operator>(const BigInteger& other) const { return other < *this; }
  bool operator<=(const BigInteger& other) const { return !(*this > other); }
  bool operator>=(const BigInteger& other) const { return !(*this < other); }
  // support unary minus
  BigInteger operator-() const {
    BigInteger result = *this;
    if (result != 0) {
      result.is_negative = !result.is_negative;
    }
    return result;
  }
  // support addition
  // 123 + 456 = 579
  // -123 + 456 = 333
  // 123 + -456 = -333
  // -123 + -456 = -579
  BigInteger operator+(const BigInteger& other) const {
    if (is_negative == other.is_negative) {
      BigInteger result;
      int carry = 0;
      int i = 0;
      while (i < digits.size() || i < other.digits.size() || carry) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
        ++i;
      }
      result.is_negative = is_negative;
      return result;
    }
    if (is_negative) {
      return other - (-*this);
    }
    return *this - (-other);
  }
  // support subtraction
  // 123 - 456 = -333
  // -123 - 456 = -579
  // 123 - -456 = 579
  // -123 - -456 = 333
  BigInteger operator-(const BigInteger& other) const {
    if (is_negative == other.is_negative) {
      if (*this == other) {
        return BigInteger(0);
      }
      if (*this < other) {
        return -(other - *this);
      }
      BigInteger result;
      int borrow = 0;
      for (int i = 0; i < digits.size(); ++i) {
        int diff = digits[i] - borrow;
        if (i < other.digits.size()) diff -= other.digits[i];
        if (diff < 0) {
          diff += 10;
          borrow = 1;
        } else {
          borrow = 0;
        }
        result.digits.push_back(diff);
      }
      while (result.digits.size() > 1 and result.digits.back() == 0) {
        result.digits.pop_back();
      }
      return result;
    }
    if (is_negative) {
      return -(-*this + other);
    }
    return *this + (-other);
  }
  // support multiplication
  // 123 * 456 = 56088
  // -123 * 456 = -56088
  // 123 * -456 = -56088
  // -123 * -456 = 56088
  BigInteger operator*(const BigInteger& other) const {
    BigInteger result;
    result.digits.resize(digits.size() + other.digits.size());
    for (int i = 0; i < digits.size(); ++i) {
      for (int j = 0; j < other.digits.size(); ++j) {
        result.digits[i + j] += digits[i] * other.digits[j];
        result.digits[i + j + 1] += result.digits[i + j] / 10;
        result.digits[i + j] %= 10;
      }
    }
    while (result.digits.size() > 1 and result.digits.back() == 0) {
      result.digits.pop_back();
    }
    result.is_negative = is_negative != other.is_negative;
    return result;
  }
  // support division
  // 123 / 456 = 0
  // -123 / 456 = 0
  // 123 / -456 = 0
  // -123 / -456 = 0
  BigInteger operator/(const BigInteger& other) const {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    BigInteger result;
    BigInteger remainder = *this;
    result.digits.resize(digits.size());
    for (int i = digits.size() - 1; i >= 0; --i) {
      remainder = remainder * 10 + digits[i];
      int quotient = 0;
      while (remainder >= other) {
        remainder = remainder - other;
        ++quotient;
      }
      result.digits[i] = quotient;
    }
    while (result.digits.size() > 1 and result.digits.back() == 0) {
      result.digits.pop_back();
    }
    result.is_negative = is_negative != other.is_negative;
    return result;
  }
  // support modulo
  // 123 % 456 = 123
  // -123 % 456 = 333
  // 123 % -456 = -333
  // -123 % -456 = -123
  BigInteger operator%(const BigInteger& other) const {
    if (other == 0) {
      throw std::runtime_error("division by zero");
    }
    BigInteger result = *this - (*this / other) * other;
    if (result.is_negative) {
      result = result + other;
    }
    return result;
  }
  // support unary plus
  BigInteger operator+() const { return *this; }
  // support increment
  BigInteger& operator++() { return *this = *this + 1; }
  BigInteger operator++(int) {
    BigInteger result = *this;
    ++*this;
    return result;
  }
  // support decrement
  BigInteger& operator--() { return *this = *this - 1; }
  BigInteger operator--(int) {
    BigInteger result = *this;
    --*this;
    return result;
  }
  // support addition assignment
  BigInteger& operator+=(const BigInteger& other) {
    return *this = *this + other;
  }
  // support subtraction assignment
  BigInteger& operator-=(const BigInteger& other) {
    return *this = *this - other;
  }
  // support multiplication assignment
  BigInteger& operator*=(const BigInteger& other) {
    return *this = *this * other;
  }
  // support division assignment
  BigInteger& operator/=(const BigInteger& other) {
    return *this = *this / other;
  }
  // support modulo assignment
  BigInteger& operator%=(const BigInteger& other) {
    return *this = *this % other;
  }
  // support output
  friend std::ostream& operator<<(std::ostream& os, const BigInteger& bigint) {
    if (bigint.is_negative) {
      os << '-';
    }
    for (auto it = bigint.digits.rbegin(); it != bigint.digits.rend(); ++it) {
      os << *it;
    }
    return os;
  }
  // support input
  friend std::istream& operator>>(std::istream& is, BigInteger& bigint) {
    std::string str;
    is >> str;
    bigint = BigInteger(str);
    return is;
  }
  // support abs
  friend BigInteger abs(const BigInteger& bigint) {
    return bigint.is_negative ? -bigint : bigint;
  }
  // support assign
  BigInteger& operator=(const BigInteger& other) {
    digits = other.digits;
    is_negative = other.is_negative;
    return *this;
  }
};