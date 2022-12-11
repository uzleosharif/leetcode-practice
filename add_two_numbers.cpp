

// you are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
// order, and each of their nodes contains a single digit. Add the 2 numbers and return the sum as a linked list.

// you may assume the 2 numbers do not contain any leading zeros, except the number 0 itself.

// constraints:
// the no. of nodes in each linked-list is in the range [1,100]
// 0 <= Node.val <= 9
// it is guaranteed that the list represents a number that does not have leading zeros

// no restriction on optimal algorithm so dont need to worry about efficiency

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

class Solution final {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // get the number by reversing linked-list
    auto getNumber{[](ListNode *l) -> int {
      std::string res_str{};
      auto x{l};
      do {
        res_str = std::to_string(x->val) + res_str;
        x = x->next;
      } while (x != nullptr);

      return std::stoi(res_str);
    }};

    auto sum_str{std::to_string(getNumber(l1) + getNumber(l2))};
    std::vector<ListNode *> tmp{};
    tmp.resize(sum_str.length());
    for (size_t i = 0; i < tmp.size(); ++i) {
      tmp[i] = new ListNode{};
    }
    for (size_t i = 0; i < tmp.size(); ++i) {
      char num{sum_str[tmp.size() - 1 - i]};
      tmp[i]->val = std::atoi(&num);
      tmp[i]->next = tmp[i + 1];
    }

    return tmp[0];
  }
};

int main() {
  //   stimuli
  ListNode l1_3{3};
  ListNode l1_2{4, &l1_3};
  ListNode l1_1{2, &l1_2};

  ListNode l2_3{4};
  ListNode l2_2{6, &l2_3};
  ListNode l2_1{5, &l2_2};

  Solution sol{};
  auto res{sol.addTwoNumbers(&l1_1, &l2_1)};

  std::cout << res->val << "\t" << res->next->val << "\t" << res->next->next->val << "\n";

  delete res->next->next;
  delete res->next;
  delete res;

  return EXIT_SUCCESS;
}