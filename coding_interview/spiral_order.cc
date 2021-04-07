#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (true) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            if (--right < left) break;

            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) break;

            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            if (++left > right) break;

        }

        return result;
    }
};