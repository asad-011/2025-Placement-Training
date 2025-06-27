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
    int pairSum(ListNode* head) {
        ListNode* mover=head;
        int maxsum=0;
        int n=0;
        vector<int> digit;
        while(mover){
            n++;
            digit.emplace_back(mover->val);
            mover=mover->next;
        }
        mover=head;
        for(int i=0; i<=n/2 ;i++){
            int sum=mover->val+digit[n-1-i];
            maxsum=max(sum,maxsum);
            mover=mover->next;
        }
        return maxsum;
    }
};
