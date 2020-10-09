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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode* root) {
        if (!root) return;
        res.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
private:
    vector<int> res;
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            res.push_back(node->val);
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return res;
    }
};