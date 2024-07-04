#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st; //store each index
        st.push(0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){ //when the value is higher than a group of values, you can keep updating res 
                int top=st.top(); //when new temperature is larger
                st.pop();
                res[top]=i-top; //iterate back on each and update res with the difference
            }
            st.push(i);
        }
        return res;
    }
};