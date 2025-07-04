class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v):key(k),val(v){}
    };

    int cap;
    unordered_map<int,Node*> mpp;

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* curr=mpp[key];
            int ans=curr->val;
            mpp.erase(key);
            
            deleteNode(curr);
            addNode(curr);
            mpp[key]=head->next;
            return ans;
        }
        return -1;
    }
    void addNode(Node* addnode){
        Node *temp=head->next;

        addnode->next=temp;
        addnode->prev=head;

        head->next=addnode;
        temp->prev=addnode;
    }
    void deleteNode(Node* delnode){
        Node* prevv=delnode->prev;
        Node* nextt=delnode->next;

        prevv->next=nextt;
        nextt->prev=prevv;
    }
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node *curr=mpp[key];
            mpp.erase(key);
            deleteNode(curr);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
