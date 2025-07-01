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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next ) return head;
        ListNode* evenhead=head->next, *even=evenhead;
        ListNode* odd=head;
        while(even && even->next ){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;












        // ListNode* evenHead=new ListNode(-1) , *evenTail=evenHead;;
        // ListNode* oddHead=new ListNode(-1);
        // ListNode* oddTail=oddHead;
        // ListNode* cur=head,*temp;
        // int count=0;
        // while(cur){
        //     temp=cur;
        //     cur=cur->next;
        //     temp->next=NULL;
        //     if(count %2==0 ){
        //         evenTail->next=temp;
        //         evenTail=temp;
        //     }
        //     else{
        //         oddTail->next=temp;
        //         oddTail=temp;
        //     }
        //     count++;
        // }
        // evenTail->next=oddHead->next;
        // return evenHead->next;
    }
};
