#include <iostream>
using namespace std;

//In terms of run time mine is still faster
class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n>0){
            if(n%2==1) ans++;
            n=n/2;
        }
        return ans;
    }
};

//TC=O(32)=O(1) using bit manipulation
class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            if((n>>i) & 1){ //& is bitwise operation 
                ans+=1;
            }
        }
        return ans;
    }
};