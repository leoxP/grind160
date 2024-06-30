#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int x=0;
        ListNode* node=head;
        while(node){
            x++;
            node=node->next;
        }
        x=ceil(x/2);
        node=head;
        while(x--){
            node=node->next;
        }
        return node;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};