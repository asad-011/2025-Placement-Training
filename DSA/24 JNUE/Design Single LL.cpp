#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node():val(0),next(nullptr){}
        Node(int v):val(v),next(nullptr){}
        Node(int v, Node *net):val(v),next(net){}
};
Node* createLL(int n){
    if(n<=0) return NULL;
    int num;
    cin>>num;
    Node* head=new Node(num);
    Node* mover=head;
    for(int i=2; i<=n ; i++){
        cin>>num;
        mover->next=new Node(num);
        mover=mover->next;
    }
    return head;
}
void traverseLL(Node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* insertintoLL(int pos, int x,Node *head){
    if(pos==1){
        Node* add=new Node(x);
        add->next=head;
        head=add;
        return head;
    }
    Node *mover=head;
    int count=1;
    while(mover!=NULL){
        if(pos==count+1){
            Node* add=new Node(x);
            add->next=mover->next;
            mover->next=add;
        }
        count++;
        mover=mover->next;
    }
    return head;
}
Node*deletefromLL(int pos,Node* head){
    if(pos==1){ return head->next; } 
    int count=1;
    Node* mover=head;
    Node* prev;
    while(mover){
        if(count==pos){
            prev->next=mover->next;
            free(mover);
            return head;
        }
        count++;
        prev=mover;
        mover=mover->next;
    }
    return head;
}
Node* deleteval(int v,Node* head){
    Node* mover=head;
    Node* prev;
    if(mover->val==v){return head->next;}
    while(mover){
        if(mover->val==v){
            prev->next=mover->next;
            free(mover);
            return head;
        }
        prev=mover;
        mover=mover->next;
    }
    return head;
}
int main(){
    int n;
    cin>>n;
    Node* head= createLL(n);
    traverseLL(head);
    head=insertintoLL(5,0, head);
    traverseLL(head);
    head=deletefromLL(5,head);
    traverseLL(head);
    head=deleteval(1, head);
    traverseLL(head);
}
