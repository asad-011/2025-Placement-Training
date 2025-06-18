/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if( head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* front=nullptr;
        ListNode* prev=nullptr;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        // stack<int> st;
        // queue<int> qt;
        // ListNode* temp=head;        //Brute
        // while(temp){
        //     st.push(temp->val);
        //     qt.push(temp->val);
        //     temp=temp->next;
        // }
        // while(!st.empty()){
        //     if(st.top()!=qt.front()) return false;
        //     st.pop();
        //     qt.pop();
        // }
        // return true;

        
        // ListNode* temp=head;
        // long long original=0;
        // long long reverse=0;
        // while(temp){
        //     int d=temp->val;
        //     original=original*10+d;
        //     temp=temp->next;
        // }
        // long long n=original;
        // while(n){
        //     int d=n%10;
        //     reverse=reverse*10+d;
        //     n=n/10;
        // }
        // return original==reverse;

        //reverse 2ndhalfLL
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverse(slow->next);
        ListNode* second=newhead;
        ListNode* first=head;
        while(second!=NULL){
            if(first->val != second->val){ 
                reverse(newhead);
                return false;}
            second=second->next;
            first=first->next;
        }
        reverse(newhead);
        return true;
    }
};
