#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> in_stk;
    std::stack<int> out_stk;
public:
    void push(int x) {
        in_stk.push(x);
    }

    int pop() {
        peek();
        int val = out_stk.top();
        out_stk.pop();
        return val;
    }

    int peek() {
        if (out_stk.empty())
            while (!in_stk.empty()) {
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        return out_stk.top();
    }

    bool empty() {
        return in_stk.empty() && out_stk.empty();
    }

};

int main() {
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    std::cout << mq.peek() << std::endl;
    std::cout << mq.pop() << std::endl;
    std::cout << mq.empty() << std::boolalpha << std::endl;
}