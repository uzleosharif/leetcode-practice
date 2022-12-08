#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <ranges>

class Solution {
 public:
  int romanToInt(std::string) const;

 private:
  const std::map<char, size_t> kAlphabetWeight{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                               {'C', 100}, {'D', 500}, {'M', 1000}};
};

int Solution::romanToInt(std::string s) const {
  // spec:
  // 1 <= s.length <= 15
  // s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M')
  // it is guaranteed that s is a valid roman numeral in the range [1,3999]
  int res{0};

  if (s.length() > 15 || s.length() < 1) {
    throw std::invalid_argument{"passed input is not in valid range"};
  }
  std::for_each(std::begin(s), std::end(s), [this, &res](const char &c) {
    if (!kAlphabetWeight.contains(c)) {
      throw std::invalid_argument{"passed input is not a roman numeral"};
    }

    res += kAlphabetWeight.at(c);
  });

  return res;
}

int main() {
  Solution sol{};

  try {
    // std::cout << sol.romanToInt("III") << "\n";
    // std::cout << sol.romanToInt("LVIII") << "\n";
    // std::cout << sol.romanToInt("MCMXCIV") << "\n";

    std::cout << sol.romanToInt("XL") << "\n";
  } catch (const std::invalid_argument &ex) {
    std::cerr << ex.what() << '\n';
  }

  return EXIT_SUCCESS;
}