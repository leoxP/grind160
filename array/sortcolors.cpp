#include<iostream>
#include<vector>
#include<map>
using namespace std;
//TC=O(N) SC=O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        nums={};
        for(auto it:mp){
            while(it.second>0){
                nums.push_back(it.first);
                it.second--;
            }
        }
    }
};