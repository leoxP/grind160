#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        unordered_map<char,char> m={{'}','{'},{']','['},{')','('}};
        for(int i=0;i<str.size();i++){
            if(str[i]=='{' || str[i]=='(' || str[i]=='['){
                s.push(str[i]);
            }
            else if(!s.empty() && m[str[i]]==s.top()){
                s.pop();
            }
            else{
                return false;
            }
        }
        return s.empty();
    }
};