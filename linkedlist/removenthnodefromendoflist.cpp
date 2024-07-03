#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//TC=O(N) one pass solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second=dummy;
        for(int i=0;i<=n;i++){
            second=second->next;
        }
        while(second){
            first=first->next;
            second=second->next;
        }
        ListNode* temp=first->next;
        first->next=first->next->next;
        delete temp;
        return dummy->next;
    }
};