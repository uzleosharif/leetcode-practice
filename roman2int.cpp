#include <array>
#include <iostream>

class Solution {
 public:
  int romanToInt(std::string) const;

 private:
  const std::array<char, 7> alphabet_{'I', 'V', 'X', 'L', 'C', 'D', 'M'};
};

int Solution::romanToInt(std::string s) const {
  // spec:
  // 1 <= s.length <= 15
  // s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M')
  // it is guaranteed that s is a valid roman numeral in the range [1,3999]
  int res{0};

  if (s.length() > 15 || s.length() < 1) {
    throw std::invalid_argument{"passed input string length is not valid"};
  }

    return res;
}

int main() {
  Solution sol{};

  try {
    std::cout << sol.romanToInt("III") << "\n";
    std::cout << sol.romanToInt("LVIII") << "\n";
    std::cout << sol.romanToInt("MCMXCIV") << "\n";
  } catch (const std::invalid_argument &ex) {
    std::cerr << ex.what() << '\n';
  }

  return EXIT_SUCCESS;
}