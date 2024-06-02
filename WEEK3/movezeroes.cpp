#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt+=1;
        }
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=0) s.push(nums[i]);
        }
        nums={};
        while(!s.empty()){
            nums.push_back(s.top());
            s.pop();
        }
        for(int i=0;i<cnt;i++){
            nums.push_back(0);
        }
    }
};

//Optimized: TC=O(N), SC=O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                l++; //l increases only after every swap
            }
            r++; //r iterates through everything
        }
    }
};