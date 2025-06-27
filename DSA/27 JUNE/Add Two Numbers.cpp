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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1=l1;
        ListNode* list2=l2;
        ListNode* ans=new ListNode(-1);
        ListNode* ansmover=ans;
        int c=0;
        int sum=0;
        
        while(list1 || list2  || c){
            int a=0,b=0;
            if(list1!=NULL){ 
                a=list1->val;
                list1=list1->next;
            }
            if(list2!=NULL) {
                b=list2->val;
                list2=list2->next;
            }
            sum=a+b+c;
            c=sum/10;
            sum=sum%10;
            
            ansmover->next= new ListNode(sum);
            ansmover=ansmover->next;
        }
        return ans->next;
    }
};
