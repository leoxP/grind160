#include<iostream>
using namespace std;

//Memoization
class Solution {
public:
    int solve(int idx,vector<int> &coins,int target,vector<vector<int>> &dp){
        if(target==0) return 0;
        if(idx<0 || target<0) return 1e8;
        
        if(dp[idx][target]!=-1) return dp[idx][target];

        int pick=1e8;
        if(target>=coins[idx]) pick=1+solve(idx,coins,target-coins[idx],dp);
        int skip=solve(idx-1,coins,target,dp);
        return dp[idx][target]=min(pick,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        if(ans==1e8) return -1;
        return ans;
    }
};

//Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        // Base cases
        for(int i=0;i<n;i++){
            dp[i][0]=0; //for target 0, every coin can be selected 0 times
        }
        for(int target=1;target<=amount;target++){
            if(target%coins[0]==0) dp[0][target]=target/coins[0]; 
            //filling up with how many times coins[0] can be used to reach target
        }
        
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<amount+1;target++){
                int pick=1e8;
                if(target>=coins[idx]) pick=1+dp[idx][target-coins[idx]];
                int skip=dp[idx-1][target];
                dp[idx][target]=min(pick,skip);
            }
        }
        int ans = dp[n - 1][amount];
        return (ans == 1e8) ? -1 : ans;
    }
};

//Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,1e8);
        vector<int> curr(amount+1,1e8);
        // Base cases
        dp[0]=0;
        curr[0]=0;
        for(int target=1;target<=amount;target++){
            if(target%coins[0]==0) dp[target]=target/coins[0]; 
            //filling up with how many times coins[0] can be used to reach target
        }
        
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<amount+1;target++){
                int pick=1e8;
                if(target>=coins[idx]) pick=1+curr[target-coins[idx]];
                int skip=dp[target];
                curr[target]=min(pick,skip);
            }
            dp=curr;
        }
        int ans = dp[amount];
        return (ans == 1e8) ? -1 : ans;
    }
};
