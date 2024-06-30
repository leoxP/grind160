#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(t.size()>s.size()) swap(s,t);
        for(auto i:s){
            m[i]++;
        }
        for(auto i:t){
            m[i]--;
            if(m[i]<=0) m.erase(i);
        }
        if(m.empty()) return true;
        return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};