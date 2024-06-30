#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
       int i=a.size()-1,j=b.size()-1;
       int carry=0;
       string res="";

       while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            carry=sum/2; //0 if only one of the numbers is 1 else 1
            res+=sum%2 + '0';
       }
       reverse(res.begin(),res.end());
       return res;
    }
};