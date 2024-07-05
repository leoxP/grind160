#include<iostream>
using namespace std;

class Solution {
public:
    void helper(string ds,vector<string> &res,int open,int close,int n){
        if(ds.size()==n*2){
            res.push_back(ds);
            return;
        }
        if(open<n){ 
            helper(ds+'(',res,open+1,close,n); //add open bracket
        }
        if(close<open){ //when open brackets are all used up
            helper(ds+')',res,open,close+1,n); //add close bracket
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",res,0,0,n);
        return res;
    }
};