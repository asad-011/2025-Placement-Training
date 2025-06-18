#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DoubleNode{
    public:
        int data;
        DoubleNode* next;
        DoubleNode* back;
    DoubleNode():data(0),next(NULL),back(NULL){};
    DoubleNode(int d):data(d),next(NULL),back(NULL){};
    DoubleNode(int d, DoubleNode* n, DoubleNode* b):data(d),next(n),back(b){};
};
DoubleNode* insertElement(DoubleNode* head, int d){
    if (head==NULL){
        DoubleNode* head=new DoubleNode(d);
        return head;
    }
    else{
        DoubleNode* mover=head;
        while(mover->next!=NULL){
            mover=mover->next;
        }
        DoubleNode* temp=new DoubleNode(d);
        mover->next=temp;
        temp->back=mover;
    }
    return head;
}
void traverseDL(DoubleNode* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
DoubleNode* converttoDL(int arr[]){
    DoubleNode* head=new DoubleNode(arr[0]);
    DoubleNode* mover= head;
    for(int i=1; i<6;i++){
        DoubleNode* temp=new DoubleNode(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=temp;
    }
    return head;
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    DoubleNode* head=converttoDL(arr);
    // DoubleNode* head=insertElement(NULL, 1);
    // head=insertElement(head, 2);
    // head=insertElement(head, 3);
    // head=insertElement(head, 4);
    // head=insertElement(head, 5);
    traverseDL(head);
    
}
