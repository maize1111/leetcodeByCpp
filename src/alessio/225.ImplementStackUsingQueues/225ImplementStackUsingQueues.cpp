#include <bits/stdc++.h>

using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        if (q1.empty())
        {
            q1.push(x);
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int res;
        if (q2.empty())
        {
            res = q1.front();
            q1.pop();
        }
        else
        {
            res = q2.front();
            q2.pop();
        }
        return res;
    }

    /** Get the top element. */
    int top()
    {
        return q1.empty() ? q2.front() : q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << '\t' << param_3 << '\t' << param_4 << endl;

    return 0;
}
