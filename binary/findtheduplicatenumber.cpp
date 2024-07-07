#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast); //they meet if there's a cycle in the list

        slow=nums[0];
        while(slow!=fast){ //when reset to start, they will meet at duplicate value
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};