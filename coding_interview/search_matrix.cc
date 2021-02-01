#include <vector>
using std::vector;
class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (auto& row: matrix) {
            for (auto num : row) {
                if (num == target) return true;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        for (auto& row: matrix) {
            if (target < row[0]) continue;
            if (target > row[row.size()-1]) continue;
            if (binarySearch(row, target)) return true;
        }
        return false;
    }

    bool binarySearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        int mid = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            if (vec[mid] == target) return true;
            else if (vec[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = 0;
        int column = matrix[0].size() - 1;

        while (row < matrix.size() && column >= 0) {
            if (target == matrix[row][column]) return true;
            else if (target < matrix[row][column]) column--;
            else if (target > matrix[row][column]) row++;
        }
        return false;
    }
};