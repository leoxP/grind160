#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<long long,long long>> s;
    long long mini=LLONG_MAX;
    MinStack() {
        
    }
    
    void push(long long val) {
        mini=min(mini,val);
        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
        if(!s.empty()){
            auto x=s.top();
            mini=x.second;
        }
        else{
            mini=LLONG_MAX;
        }
    }
    
    long long top() {
        return s.top().first;
    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */