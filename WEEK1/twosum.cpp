#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if(map.find(target-n)!=map.end()){
                return {i,map[target-n]};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};