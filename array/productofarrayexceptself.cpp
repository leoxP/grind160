#include<iostream>
#include<vector>
using namespace std;

//TC=O(N) SC=O(N) due to extra array used [Prefix SUffix Method]
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l(nums.size());
        vector<int> r(nums.size());
        int p=1;
        l[0]=1;
        for(int i=0;i<nums.size()-1;i++){
            p*=nums[i];
            l[i+1]=p;
        }
        p=1;
        r[nums.size()-1]=1;
        for(int i=nums.size()-1;i>0;i--){
            p*=nums[i];
            r[i-1]=p;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=l[i]*r[i];
        }
        return nums;
    }
};

//Optimized TC=O(N) SC=O(1) [Result array is not counted]
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int leftProduct=1;
        //calculate products to left
        for(int i=0;i<n-1;++i){
            leftProduct*=nums[i];
            res[i+1]=leftProduct;
        }
        int rightProduct=1;
        //multiply by products to right
        for(int i=n-1;i>=0;i--){
            res[i]*=rightProduct;
            rightProduct*=nums[i];
        }
        return res;
    }
};