#include <string>
#include <vector>
#include <iostream>
int kmp(std::string& txt, std::string& pat, std::vector<int>& next)
{
    //TODO: not empty assert
    int i = 0;
    int j = 0;
    while (i < txt.size() && j < pat.size()) {
        if (j == -1 || txt[i] == pat[j]) {
            ++i;
            ++j;
        } else 
            j = next[j];
    }
    if (j == pat.size())
        return i - j;
    else 
        return -1;
}

std::vector<int> get_next(std::string& pat)
{
    std::vector<int> next(pat.size());
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < pat.size() - 1) {
        if (j ==-1 || pat[i] == pat[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else 
            j = next[j];
    }
    return next;
}

int main()
{
    std::string txt("ababababca");
    std::string pat("abababca");
    std::vector<int> next = std::move(get_next(pat));
    int result = kmp(txt, pat, next);
    std::cout << "the value: " << result << std::endl;
}