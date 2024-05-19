#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        if(head==nullptr) return false;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }
};