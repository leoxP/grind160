#include<iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int n){ //Just random function internal
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        if(!isBadVersion(n)) return n+1;

        return firstBadVersion(n-1);
    }
};

//Optimized solution: Binary Search: TC=O(logn)
class Solution {
public:
    long long firstBadVersion(long long n) {
        long long l=1,h=n;

        while(l<h){
            long long m=(l+h)/2;
            if(isBadVersion(m)){
                h=m;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};