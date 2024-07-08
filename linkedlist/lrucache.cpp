#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k,int v){
            key=k;
            val=v;
        }
    };

    node* head=new node(-1,-1);
    node* tail=new node(-1,-1); //DLL created
    
    int cap; //global capacity
    unordered_map<int,node*> m; //stores key and pointer value

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head; //intialize DLL
    }

    void addnode(node* curr){
        node* temp=head->next;
        curr->next=temp;
        curr->prev=head;
        head->next=curr;
        temp->prev=curr; //insert new node to next of head
    }

    void deletenode(node* curr){
        node* delprev=curr->prev;
        node* delnext=curr->next;
        delprev->next=delnext;
        delnext->prev=delprev; //delete the node and update its surrounding values
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* curr=m[key];
            int res=curr->val;
            m.erase(key);
            deletenode(curr);
            addnode(curr);
            //m[key]=head->next;
            m[key]=curr;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* curr=m[key];
            m.erase(key);
            deletenode(curr);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};