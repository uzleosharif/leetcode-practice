

// given an array of integers nums and an integer target, return indices of the two numbers such that they add up to
// target. you may assume that each input would have exactly one solution, and you may not use the same element twice
// you can return the answer in any order

// nums = [2,7,11,15], target = 9 -> [0,1]
// [3,2,4], 6 -> [1,2]

// nums = [3,3], target = 6 -> [0,1]

// constraints:
// only one valid answer exists

// < O(n^2)??

// [11, 15, 2, 7]

#include <iostream>
#include <vector>

class Solution final {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    static int i1{-1};
    i1++;

    // recursive
    int i2{i1};
    for (auto it{std::begin(nums) + 1}; it != std::end(nums); ++it) {
      i2++;

      if (*it + nums[0] == target) {
        return {i1, i2};
      }
    }

    std::vector<int> reduced_nums{std::begin(nums) + 1, std::end(nums)};
    return twoSum(reduced_nums, target);
  }
};

int main() {
  std::vector<int> nums{11, 15, 2, 7};
  int target{9};

  Solution sol{};
  auto res{sol.twoSum(nums, target)};
  std::cout << res[0] << "," << res[1] << "\n";

  return EXIT_SUCCESS;
}