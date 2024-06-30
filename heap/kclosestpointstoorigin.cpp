#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>> v;
        for(int i=0;i<points.size();i++){
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop(); //Remove the top largest distances
            }
        }
        while(k--){
            pair<int,int> p=pq.top().second;
            v.push_back(vector<int> {p.first,p.second}); //push the k closest distances
            pq.pop();
        }

        return v;
    }
};