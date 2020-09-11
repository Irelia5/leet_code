#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while (i < j) {
            res = height[i] < height[j] ? max(res, (j - i) * height[i++]) : max(res, (j - i) * height[j--]);
        }
        return res;
    }

    int max(int a, int b) { return a > b ? a : b; }
};