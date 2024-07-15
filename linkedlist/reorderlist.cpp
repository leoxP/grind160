#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//TC=O(N) SC=O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* dummy=head;
        while(dummy){
            st.push(dummy);
            dummy=dummy->next;
        }
        dummy=head;
        int n=st.size();
        for(int i=0;i<n/2;i++){
            ListNode* tail=st.top();
            st.pop();

            tail->next=dummy->next;
            dummy->next=tail;
            dummy=tail->next;
        }
        dummy->next=nullptr;
    }
};

//TC=O(N) SC=O(1) using 2 Pointer
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=nullptr;
        ListNode* curr=slow->next; //middle pointer or +1 in even number case
        slow->next=nullptr;
        while(curr){ //reverse second half of list
            ListNode* nextVal=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextVal;
        }

        ListNode* first=head;
        ListNode* second=prev; //prev is start of reversed list
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};
