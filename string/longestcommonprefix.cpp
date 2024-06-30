#include<iostream>
#include<vector>
using namespace std;

// O(n*m) solution:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min=99999;
        string x;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<min){
                x=strs[i];
                min=strs[i].size();
            }
        }
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]==x[j]) continue;
                else{
                    x=x.substr(0,j);
                    break;
                }
            }
        }
        return x;
    }
};

// O(NlogN) solution (Sorting)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int x=strs.size();
        string n=strs[0]; //First String (Shortest)
        string m=strs[x-1]; //Last string (Longest)
        string ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]) ans+=n[i];
            else break;
        }
        return ans;
    }
};