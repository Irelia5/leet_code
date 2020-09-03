#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int start = 0;
        int cur = 0;
        int end = nums.size();
        int max = 0;
        while (cur != end) {
            while (start != end && nums[start] != 1) ++start;
            cur = start;
            while (cur != end && nums[cur] == 1) ++cur;
            max = max > (cur - start) ? max : (cur - start);
            start = cur;
        }
        return max;
    }
};