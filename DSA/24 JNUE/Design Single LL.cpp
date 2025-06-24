#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class SinglyLinkedList {
private:
    ListNode* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        ListNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert at any index (0-based)
    void insertAtIndex(int index, int val) {
        if (index < 0) {
            cout << "Invalid index.\n";
            return;
        }

        if (index == 0) {
            insertAtBeginning(val);
            return;
        }

        ListNode* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Index out of bounds.\n";
            return;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        ListNode* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at index
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) {
            cout << "Invalid operation.\n";
            return;
        }

        if (index == 0) {
            deleteAtBeginning();
            return;
        }

        ListNode* temp = head;
        for (int i = 0; temp->next != nullptr && i < index - 1; ++i) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Index out of bounds.\n";
            return;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete first occurrence of value
    void deleteValue(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->val == val) {
            deleteAtBeginning();
            return;
        }

        ListNode* temp = head;
        while (temp->next != nullptr && temp->next->val != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found.\n";
            return;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Print the linked list
    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ---------- Main Function to Test ----------
int main() {
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtIndex(1, 15); // [5, 15, 10, 20]
    list.printList();

    list.deleteAtBeginning();  // [15, 10, 20]
    list.deleteAtEnd();        // [15, 10]
    list.deleteAtIndex(0);     // [10]
    list.insertAtEnd(25);
    list.insertAtEnd(30);
    list.deleteValue(25);      // [10, 30]

    list.printList();

    return 0;
}

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//         int val;
//         Node *next;
//         Node():val(0),next(nullptr){}
//         Node(int v):val(v),next(nullptr){}
//         Node(int v, Node *net):val(v),next(net){}
// };
// Node* createLL(int n){
//     if(n<=0) return NULL;
//     int num;
//     cin>>num;
//     Node* head=new Node(num);
//     Node* mover=head;
//     for(int i=2; i<=n ; i++){
//         cin>>num;
//         mover->next=new Node(num);
//         mover=mover->next;
//     }
//     return head;
// }
// void traverseLL(Node* head){
//     while(head){
//         cout<<head->val<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// Node* insertintoLL(int pos, int x,Node *head){
//     if(pos==1){
//         Node* add=new Node(x);
//         add->next=head;
//         head=add;
//         return head;
//     }
//     Node *mover=head;
//     int count=1;
//     while(mover!=NULL){
//         if(pos==count+1){
//             Node* add=new Node(x);
//             add->next=mover->next;
//             mover->next=add;
//         }
//         count++;
//         mover=mover->next;
//     }
//     return head;
// }
// Node*deletefromLL(int pos,Node* head){
//     if(pos==1){ return head->next; } 
//     int count=1;
//     Node* mover=head;
//     Node* prev;
//     while(mover){
//         if(count==pos){
//             prev->next=mover->next;
//             free(mover);
//             return head;
//         }
//         count++;
//         prev=mover;
//         mover=mover->next;
//     }
//     return head;
// }
// Node* deleteval(int v,Node* head){
//     Node* mover=head;
//     Node* prev;
//     if(mover->val==v){return head->next;}
//     while(mover){
//         if(mover->val==v){
//             prev->next=mover->next;
//             free(mover);
//             return head;
//         }
//         prev=mover;
//         mover=mover->next;
//     }
//     return head;
// }
// int main(){
//     int n;
//     cin>>n;
//     Node* head= createLL(n);
//     traverseLL(head);
//     head=insertintoLL(5,0, head);
//     traverseLL(head);
//     head=deletefromLL(5,head);
//     traverseLL(head);
//     head=deleteval(1, head);
//     traverseLL(head);
// }
