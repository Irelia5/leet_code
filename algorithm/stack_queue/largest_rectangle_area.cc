#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) return heights[0];
        unsigned long size = heights.size();
        stack<int> index_stack;
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!index_stack.empty() && heights[i] < heights[index_stack.top()]) {
                int length = heights[index_stack.top()];
                index_stack.pop();
                int width = i;
                if (!index_stack.empty()) {
                    width = i - index_stack.top() - 1;
                }
                res = max(res, width * length);
            }
            index_stack.push(i);
        }

        while (!index_stack.empty()) {
            int length = heights[index_stack.top()];
            index_stack.pop();
            int width = size;
            if (!index_stack.empty()) {
                width = size - index_stack.top() -1;
            }
            res = max(res, width * length);
        }
        return res;
    }
};



