#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char c: s) {
            switch (c) {
                case '(' : paren.push(')'); break;
                case '[' : paren.push(']'); break;
                case '{' : paren.push('}'); break;
                default : if (paren.empty() || paren.top() != c) return false;
                            else paren.pop();
            }
        }
        return paren.empty();
    }
};
