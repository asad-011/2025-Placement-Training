/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x==1) return head->next;
        Node *temp=head;
        Node *prev;
        int count=1;
        while(temp){
            if(count==x){
                prev->next=temp->next;
                temp->next=nullptr;
            }
            count++;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
