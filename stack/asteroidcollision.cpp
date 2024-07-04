#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> st;
        for(auto i:asteroids){
            bool destroyed=false;
            while(!st.empty() && i<0 && st.top()>0){
                if(abs(i)>abs(st.top())){
                    st.pop();
                }
                else if(abs(i)==abs(st.top())){
                    st.pop();
                    destroyed=true; //current asteroid destroyed
                    break;
                }
                else{
                    destroyed=true; //current asteroid destroyed
                    break;
                }
            }
            if(!destroyed) st.push(i);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};