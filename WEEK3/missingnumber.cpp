#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*(nums.size()+1))/2;
        for(auto i:nums){
            sum-=i;
        }
        return sum;
    }
};

//Alternate solution without Maths approach:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];
        }
        return res;        
    }
};