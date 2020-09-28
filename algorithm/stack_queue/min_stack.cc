#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        the_stack_.push(x);
        if (min_stack_.empty() || x <= min_stack_.top()) min_stack_.push(x);
    }
    
    void pop() {
        if (the_stack_.top() == getMin()) min_stack_.pop();
        the_stack_.pop();
    }
    
    int top() {
        return the_stack_.top();
    }
    
    int getMin() {
        return min_stack_.top();
    }
private:
    stack<int> the_stack_;
    stack<int> min_stack_;
};