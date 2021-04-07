#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> printNumbers(int n) {

    }
};

const int kNumber = 3;
string result;
char loop[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char num[kNumber];

void dfs(int x)
{
    if (x == kNumber) {
        string str(num);
        string res;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') continue;
            else {
                res = str.substr(i);
                break;
            }
        }
        if (!res.empty()) {
            result.append(res).append(",");
        }
        return;
    }
    for (char ch : loop) {
        num[x] = ch;
        dfs(x + 1);
    }
}

int main()
{
    dfs(0);
    std::cout << result << std::endl;
    return 0;
}