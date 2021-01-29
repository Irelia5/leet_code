#include <vector>
#include <string>
using namespace std;

/**
 * 可以想象，这样的左括号和右括号类似于二叉树的左子树和右子树
 * 于是解题方法变成了树的遍历
 * 
 * 可采用方法：
 * 1. 深度优先搜索
 * 2. 广度优先搜索
 * 
 * 
 * 1. 深度优先搜索
 * 思路：
 * 生成一个左子树条件：左括号数严格大于0
 * 生成右子树条件：左括号数严格大于右括号数
 * 
 * 跳出（结算）：左括号数和右括号数均为0
 * 
 * 2. 广度优先遍历其实就是自己构造一个数据结构，然后进行，剪枝和深度优先搜索一致
 * 
 * 
 * 
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        dfs("", n, n, res);
        return res;
    }

    void dfs(string cur_str, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(cur_str);
            return ;
        }
        if (left > 0) {
            dfs(cur_str + "(", left - 1, right, res);
        }
        if (right > left) {
            dfs(cur_str + ")", left, right - 1, res);
        }
        return ;
    }
};