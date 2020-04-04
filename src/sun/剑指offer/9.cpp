#include <bits/stdc++.h>
using namespace std;
//使用两个栈实现队列
class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);

    }
    
    int deleteHead() {
        if(s1.empty()&&s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
};