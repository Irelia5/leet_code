#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i]);
        }
    }
    void reverse(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() / 2; ++i) {
            std::swap(nums[i], nums[nums.size() - 1 - i]);
        }
    }
};