#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int num = 0;
        for (int element : nums) {
            if (cnt == 0) num = element;
            if (num == element) cnt++;
            else cnt--;
        }
        return num;
    }
};