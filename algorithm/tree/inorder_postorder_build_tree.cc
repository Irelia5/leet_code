#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;


/**
 * 中序和后序建立二叉树
 * 首先要明白为什么只中序或只后序不能确定唯一一棵树。
 * 后序能确定根结点位置，但是不能确定左右子树，而中序如果知道根结点能区分左右子树，这样完成一棵树的唯一确定。
 * 
 * 思路：
 * 关于树的算法递归思维是最重要的，把握一个结点，就能处理整个树结构。
 * 
 * 思路：
 * 1. 从后序中取最后一个元素，必定是根结点
 * 2. 从中序中找到这个元素的位置，区分左子树的那些结点和右子树的那些结点，无需关注具体结点，只需知道左子树结点个数
 * 3. 知道左子树结点个数，因此将后序切分为两部分，分别是左子树和右子树部分，中序也同样如此
 * 4. 将切分后的后序进行思路1，完成递归
 * 
 * 跳出部分：后序中只有一个结点，则该结点为叶子结点
 * 
 * 
 * 工具：
 * 数组的下标作为切分
 * 中序建立hash，映射下标
 * 
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_ = postorder;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_hash_[inorder[i]] = i;
        }
        return build(0, inorder.size(), 0, postorder.size());
    }

    TreeNode* build(int inorder_start, int inorder_end, int postorder_start, int postorder_end)
    {
        if (postorder_start == postorder_end) return nullptr;
        TreeNode* node = new TreeNode(postorder_[postorder_end-1]);
        int index = inorder_hash_[postorder_[postorder_end-1]];
        node->left = build(inorder_start, index, postorder_start, postorder_start + index - inorder_start);
        node->right = build(index+1, inorder_end, postorder_end + index - inorder_end, postorder_end-1);
        return node;
    }

private:
    unordered_map<int, int> inorder_hash_;
    vector<int> postorder_;
};