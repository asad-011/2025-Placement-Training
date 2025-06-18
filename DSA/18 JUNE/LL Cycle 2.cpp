// set<ListNode*> st;                //Brute
        // ListNode* temp=head;
        // while(temp){
        //     if(st.find(temp)!=st.end()) return true;
        //     st.emplace(temp);
        //     temp=temp->next;
        // }
        // return false;

        //optimal  tortoise and Hare Algorithm 
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        return false;
