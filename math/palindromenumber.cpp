#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long y=x;
        long long ans=0;
        while(x!=0){
            int y=x%10;
            ans=(ans*10)+y;
            x/=10;
        }
        return ans==y;
    }
};

//SC=O(1) approach
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false; //Negative numbers and numbers that end with 0 but not 0 itself
        int half=0;
        while(x>half){
            half=(half*10)+(x%10);
            x/=10;
        }
        return (x==half) || (x==(half/10)); //To consider situations for odd number of digits
    }
};