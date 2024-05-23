#include<iostream>
#include<vector>
#include<map>
using namespace std;

// TC=O(N) SC=O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};

// TC=O(N) SC=O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto it:nums){
            x^=it; //XOR method
        }
        return x;
    }
};