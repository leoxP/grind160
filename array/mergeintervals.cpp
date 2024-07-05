#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int x=0;
        while(x<intervals.size()){
            int start=intervals[x][0];
            int end=intervals[x][1];
            while(x<intervals.size()-1 && end>=intervals[x+1][0]){
                end=max(end,intervals[x+1][1]);
                x++;
            }
            res.push_back({start,end});
            x++;
        }
        return res;
    }
};