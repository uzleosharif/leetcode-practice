

// given a string s, find the length of the longest substring without repeating characters.

// "abcabcbb" -> 3
// "bbbbb" -> 1
// "pwwkew" -> 3

// constraints:
// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces

#include <iostream>
#include <set>
#include <string>
#include <tuple>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    size_t res{0};

    for (auto [it, cnt] = std::tuple{std::begin(s), 1}; it != std::end(s); ++it, ++cnt) {
      if (res > (s.length() - cnt)) {
        break;
      }

      std::set<char> already_seen{*it};
      for (auto [to_break, it2, len] = std::tuple{false, it + 1, 1};; ++it2, ++len) {
        if (already_seen.contains(*it2)) {
          to_break = true;
        }
        already_seen.emplace(*it2);

        if (!to_break) {
          if (it2 == (std::end(s) - 1)) {
            len++;
            to_break = true;
          }
        }

        if (to_break) {
          res = (len > res) ? len : res;
          break;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution sol{};
  auto l{sol.lengthOfLongestSubstring(std::string{"bbbbb"})};
  std::cout << l << "\n";

  return EXIT_SUCCESS;
}