#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        else if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);      
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        std::vector steps(n, 0);
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < n; ++i) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n-1];
    }
};
