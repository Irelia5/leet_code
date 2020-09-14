#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (sum == 0) {
                    res.push_back({nums[i], nums[front], nums[back]});
                    while (front < back && nums[front] == nums[front+1]) ++front;
                    while (front < back && nums[back] == nums[back-1]) --back;
                    ++front, --back;
                } else if (sum < 0) {
                    ++front;
                } else {
                    --back;
                }
            }
        }
        return res;
    }
};