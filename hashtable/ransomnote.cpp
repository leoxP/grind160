#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(auto it:ransomNote){
            m[it]++;
        }
        for(auto it:magazine){
            if(m[it]>=1) m[it]--;
            if(m[it]==0) m.erase(it);
        }
        if(m.empty()) return true;
        return false;
    }
};