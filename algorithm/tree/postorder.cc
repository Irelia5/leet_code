#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 方法分为迭代和递归两种
 * 递归比较简单
 * 迭代方法有几种
 * 1. 标记已遍历结点（逻辑直观）
 * 2. 后序遍历为左右根，而前序为根左右，只需将前序方法改为根右左，再逆置数组即可（巧）
 * 3. 结点标记法，设定伪结点作为标记（类似定式，可以通用于前序中序后序）
 */


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> the_stack;
        TreeNode* prev = nullptr;
        while (root != nullptr || !the_stack.empty()) {
            while (root != nullptr) {
                the_stack.emplace(root);
                root = root->left;
            }
            root = the_stack.top();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                the_stack.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
    }
};