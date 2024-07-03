#include<iostream>
#include<unordered_map>
using namespace std;

//TC=O(N) using prefix sum method
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum=0;
        int cnt=0;
        unordered_map<int,int> m;
        m[psum]=1; //for including first value as psum
        for(auto i:nums){
            psum+=i;
            if(m.find(psum-k)!=m.end()){
                cnt+=m[psum-k];
            }
            m[psum]++;
        }
        return cnt;
    }
};