#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto it:s){
            m[it]++;
        }

        bool odd=false;
        int count=0;

        for(auto&pair:m){
            count+=(pair.second/2) *2;
            if(pair.second%2!=0){
                odd=true;
            }
        }
        return odd? count+1:count;
    }
};