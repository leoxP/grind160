#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++){
            profit=max(prices[i]-mp,profit);
            mp=min(prices[i],mp);
        }
        
        return profit;
    }
};