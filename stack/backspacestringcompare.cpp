#include<iostream>
#include<stack>
using namespace std;

//SC=O(N)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(auto i:s){
            if(i=='#') {
                if(!st1.empty())
                    st1.pop();
            }
            else st1.push(i);
        }
        for(auto i:t){
            if(i=='#') {
                if(!st2.empty())
                    st2.pop();
            }
            else st2.push(i);
        }
        stack<char> a=st1,b=st2;
        while(!a.empty()){
            cout<<a.top()<<endl;
            a.pop();
        }
        while(!b.empty()){
            cout<<b.top()<<endl;
            b.pop();
        }
        while(!st1.empty() || !st2.empty()){
            if(st1.empty() && !st2.empty()) return false;
            if(!st1.empty() && st2.empty()) return false;
            char x=st1.top(),y=st2.top();
            if(x==y){
                st1.pop();
                st2.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};

//SC=O(1) Two Pointer Method
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        while(i>=0 || j>=0){
            int skipS=0,skipT=0;
            while(i>=0){
                if(s[i]=='#'){
                    i--;
                    skipS++;
                }
                else if(skipS>0){
                    i--;
                    skipS--;
                }
                else{ //if neither # or skip>0
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    j--;
                    skipT++;
                }
                else if(skipT>0){
                    j--;
                    skipT--;
                }
                else{ //if neither # or skip>0
                    break;
                }
            }
            if(i>=0 && j>=0 && s[i]!=t[j]){ //if characters don't match
                return false;
            }
            if((i>=0)!=(j>=0)){ //If i has reached 0 and j hasnt and vice versa
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};