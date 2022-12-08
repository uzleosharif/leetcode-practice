

// consider all the leaves of a binary tree, from left to right order, the values of those leaves
// form a leaf value sequence
// e.g. [6, 7, 4, 9, 8]
// 2 binary trees are considered leaf-similar if their leaf value sequence is the same.

// return true if and only if the 2 given rees with head nodes root1, root2 are leaf-similar.

// constraints:
// num. of nodes in each tree will be in the range [1,200]
// both of the given trees will have values in the range [0,200]

#include <functional>
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int x) : val(x), left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val{x}, left{left}, right{right} {}
};

class Solution final {
 public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    auto lvs_1{dfs(root1)};
    auto lvs_2{dfs(root2)};

    if (lvs_1 == lvs_2) {
      return true;
    } else {
      return false;
    }
  }

  // keep on traversing until you hit a leaf node (recursion!!)
  std::vector<int> dfs(TreeNode *root) {
    // depth-first search of binary tree that makes sure that left-right order is maintained
    // post-order traversal (left, right, root)

    std::vector<int> res{};
    if (root->left == nullptr && root->right == nullptr) {
      return {root->val};
    }

    res = dfs(root->left);
    auto right_side{dfs(root->right)};
    std::move(std::begin(right_side), std::end(right_side), std::back_inserter(res));

    return res;
  }
};

int main() {
  // tree 1
  TreeNode node1{7};
  TreeNode node2{4};
  TreeNode node3{9};
  TreeNode node4{8};
  TreeNode node5{6};
  TreeNode node6{2, &node1, &node2};
  TreeNode node7{5, &node5, &node6};
  TreeNode node8{1, &node3, &node4};
  TreeNode root1{3, &node7, &node8};

  // tree 2
  TreeNode node_1{6};
  TreeNode node_2{7};
  TreeNode node_3{4};
  TreeNode node_4{9};
  TreeNode node_5{8};
  TreeNode node_6{2, &node_4, &node_5};
  TreeNode node_7{1, &node_3, &node_6};
  TreeNode node_8{5, &node_1, &node_2};
  TreeNode root2{3, &node_8, &node_7};

  Solution sol{};
  auto res{sol.leafSimilar(&root1, &root2)};
  std::cout << res << "\n";

  return 0;
}