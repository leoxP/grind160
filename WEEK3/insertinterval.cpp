#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans={};
        int i=0;
        while(i<intervals.size() && newInterval[0]>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        } //i is the interval before the interval at which it's located
        while(i<intervals.size() && newInterval[1]>=intervals[i][0]){
            newInterval={min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        } //merges the intervals for which newInterval is located in
        ans.push_back(newInterval);
        while (i < intervals.size()) {
            ans.push_back(intervals[i]); //pushes the intervals afterwards
            i++;
        }
        return ans;
    }
};