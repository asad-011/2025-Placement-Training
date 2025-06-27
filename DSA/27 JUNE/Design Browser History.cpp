class BrowserNode {
public:
    string url;
    BrowserNode* prev;
    BrowserNode* next;
    BrowserNode(string ur) : url(ur), next(nullptr), prev(nullptr) {}
};
class BrowserHistory {
    BrowserNode* curr;

public:
    BrowserHistory(string homepage) {
        BrowserNode* temp = new BrowserNode(homepage);
        curr = temp;
    }

    void visit(string url) {
        BrowserNode* temp = new BrowserNode(url);
        delete(curr->next);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    string back(int steps) {
        int n = steps;
        while (curr->prev != NULL && n--) {
            curr = curr->prev;
        }
        return curr->url;
    }

    string forward(int steps) {
        int n = steps;
        while (curr->next && n--) {
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
