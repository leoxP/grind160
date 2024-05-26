#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* start=head;
        string x="";
        while(start){
            x+=char(start->val+'0');
            start=start->next;
        }
        for(int i=0;i<x.size()/2;i++){
            if(x[i]!=x[x.size()-i-1]) return false;
        }
        return true;
    }
};

// Using stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        stack<int> st;
        while(curr){
            st.push(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr && curr->val==st.top()){
            st.pop();
            curr=curr->next;
        }
        return curr==nullptr;
    }
};

//Using Recursion
class Solution {
public:
    bool solve(ListNode* head, ListNode* &curr){
        if(!head) return true;
        bool ans=solve(head->next,curr) && curr->val==head->val;
        curr=curr->next;
        return ans;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        return solve(head,curr);
    }
};