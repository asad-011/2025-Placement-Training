#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
        // ListNode():data(0),next(NULL){}
        ListNode(int d):data(d),next(NULL){}
        ListNode(int d, ListNode* n):data(d),next(n){}
};
ListNode* convert2LL(int arr[]){
    ListNode* mover=new ListNode(arr[0]);
    for(int i=1; i<5; i++){
        ListNode* temp=new ListNode(arr[i]);
        temp->next=mover;
        mover=temp;
    }
    return mover;
}
void traverseLL(ListNode* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
ListNode* insertElement(ListNode* head, int d){
    ListNode* mover=head;
    if(head==NULL){
        ListNode* head=new ListNode(d);
        return head;
    }
    else{
        while(mover->next != NULL){
            mover=mover->next;
        }
        ListNode* temp=new ListNode(d);
        mover->next=temp;
    }
    return head;
}
ListNode* DeleteNode(ListNode* head, int del){
    if(head->data==del){
        head=head->next;
        return head;
    }
    ListNode* mover=head;
    while(  mover!=NULL ){
        if(mover->next->data==del){
            mover->next=mover->next->next;
            break;
        }
        mover=mover->next;
        if(mover->next==NULL) {cout<<"NOT FOUND!"<<del; break;}
    }
    
    return head;

}
int lengthofLL(ListNode* head){
    int count=0;
    while(head !=NULL){
        head=head->next;
        count++;
    }
    return count;
}
ListNode* reverseLL(ListNode* head){
    ListNode* mover=head;
    ListNode* prev=nullptr;
    ListNode* front;
    while(mover!=NULL){
        front=mover->next;
        mover->next=prev;
        prev=mover;
        mover=front;
    }
    return prev;
}
int main(){
    int arr[5]={1,2,3,4,5};
    // ListNode* head=convert2LL(arr);
    // traverseLL(head);
    ListNode* head=insertElement(NULL , 1);
    head=insertElement(head, 2);
    head=insertElement(head, 3);
    head=insertElement(head, 4);
    head=insertElement(head, 5);
    traverseLL(head);
    head=DeleteNode(head, 5);
    traverseLL(head);
    // cout<<lengthofLL(head);
    head=reverseLL(head);
    traverseLL(head);

}
