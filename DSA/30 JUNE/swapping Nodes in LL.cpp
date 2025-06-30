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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mover=head;
        int n=0;
        while(mover){
            n++;
            mover=mover->next;
        }
        mover=head;
        int count=0;
        ListNode* temp;
        ListNode* temp2;
        while(mover){
            count++;
            if(count==k) temp=mover;
            if(count==n-k+1) temp2=mover;
            mover=mover->next;
        }
        if(temp!=NULL && temp2!=NULL) {swap(temp->val,temp2->val);}
        return head;
    }
};
