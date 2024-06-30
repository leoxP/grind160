#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            int e=s1.top();
            s2.push(e);
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            int e=s2.top();
            s1.push(e);
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
         while(!s1.empty()){
            int e=s1.top();
            s2.push(e);
            s1.pop();
        }
        int ans=s2.top();
        while(!s2.empty()){
            int e=s2.top();
            s1.push(e);
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};

//More efficient approach: (Amortized O(1) operation for both peek and pop instead of O(N))
class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};