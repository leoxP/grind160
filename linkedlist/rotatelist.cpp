#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//TC=O(N+K) SC=O(N)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        stack<ListNode*> st;
        ListNode* dummy=head;
        while(dummy){
            st.push(dummy);
            dummy=dummy->next;
        }
        k%=st.size();
        for(int i=0;i<k;i++){
            ListNode* newhead=st.top();
            st.pop();
            ListNode* tail=st.top();
            tail->next=nullptr;
            newhead->next=head;
            head=newhead;
        }
        return head;
    }
};

//TC=O(N) SC=O(1)
