#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <ranges>
#include <string>

namespace util {
// returns count of non-overlapping occurrences of 'sub' in 'str'
inline int countSubstring(const std::string& str, const std::string& sub) {
  if (sub.length() == 0) return 0;
  int count = 0;
  for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length())) {
    ++count;
  }
  return count;
}
}  // namespace util

class Solution {
 public:
  int romanToInt(std::string) const;

 private:
  const std::map<char, size_t> kAlphabetWeight{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                               {'C', 100}, {'D', 500}, {'M', 1000}};
  void correction(const std::string& s, int& res) const;
};

void Solution::correction(const std::string& s, int& res) const {
  // correction needed for special cases
  // there are 6 instances where subtraction is used:
  // 'I' can be placed before V and X -> subtract by 1
  // 'X' can be placed before L and C -> subtract by 10
  // 'C' can be placed before D and M -> subtract by 100

  res -= (util::countSubstring(s, "IX") * kAlphabetWeight.at('I') * 2);
  res -= (util::countSubstring(s, "IV") * kAlphabetWeight.at('I') * 2);

  res -= (util::countSubstring(s, "XL") * kAlphabetWeight.at('X') * 2);
  res -= (util::countSubstring(s, "XC") * kAlphabetWeight.at('X') * 2);

  res -= (util::countSubstring(s, "CD") * kAlphabetWeight.at('C') * 2);
  res -= (util::countSubstring(s, "CM") * kAlphabetWeight.at('C') * 2);
}

int Solution::romanToInt(std::string s) const {
  // spec:
  // 1 <= s.length <= 15
  // s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M')
  // it is guaranteed that s is a valid roman numeral in the range [1,3999]
  int res{0};

  if (s.length() > 15 || s.length() < 1) {
    throw std::invalid_argument{"passed input is not in valid range"};
  }
  std::for_each(std::begin(s), std::end(s), [this, &res](const char& c) {
    if (!kAlphabetWeight.contains(c)) {
      throw std::invalid_argument{"passed input is not a roman numeral"};
    }

    res += kAlphabetWeight.at(c);
  });
  correction(s, res);

  return res;
}

int main() {
  Solution sol{};

  try {
    std::cout << sol.romanToInt("III") << "\n";
    std::cout << sol.romanToInt("LVIII") << "\n";
    std::cout << sol.romanToInt("MCMXCIV") << "\n";

  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what() << '\n';
  }

  return EXIT_SUCCESS;
}