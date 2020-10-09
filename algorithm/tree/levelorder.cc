#include <vector>
#include <stack>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> the_queue;
        if (root != nullptr) the_queue.push(root);
        while (!the_queue.empty()) {
            int the_size = the_queue.size();
            vector<int> level;
            for (int i = 0; i < the_size; ++i) {
                TreeNode* node = the_queue.front();
                the_queue.pop();
                level.push_back(node->val);
                if (node->left != nullptr) the_queue.push(node->left);
                if (node->right != nullptr) the_queue.push(node->right);
            }
            res.push_back(std::move(level));
        }
        return res;
    }
};