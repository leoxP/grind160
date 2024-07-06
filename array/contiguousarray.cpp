#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int> m;
        m[0]=-1; //zero diff at -1 initialized
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) cnt2++;
            else cnt1++;
            int diff=cnt1-cnt2;
            if(m.find(diff)!=m.end()){
                maxi=max(maxi,i-m[diff]);
            }
            else{
                m[diff]=i;
            }
        }
        return maxi;
    }
};