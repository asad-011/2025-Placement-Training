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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mover=head;
        ListNode* curr=head;
        ListNode* temp;
        int size=0;
        while(curr){
            size++;
            curr=curr->next;
        }
        k=k%size;
        while(k){
            while(mover && mover->next && mover->next->next != NULL){
                mover=mover->next;
            }
            temp=mover;
            mover=mover->next;
            temp->next=nullptr;
            mover->next=head;
            head=mover;
            k--;
        }
        return head;
    }
};
