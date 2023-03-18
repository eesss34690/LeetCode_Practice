class BrowserHistory {
public:
    struct History {
        string url;
        History* next = NULL;
        History* prev = NULL;
    };
    History* iter;
    BrowserHistory(string homepage) {
        iter = new History();
        iter->url = homepage;
    }
    
    void visit(string url) {
        History* temp = new History();
        temp->url = url;
        temp->prev = iter;
        iter->next = temp;
        iter = iter->next;
    }
    
    string back(int steps) {
        while (steps > 0)
        {
            if (iter->prev == NULL)
                break;
            iter = iter->prev;
            steps--;
        }
        return iter->url;
    }
    
    string forward(int steps) {
        while (steps > 0)
        {
            if (iter->next == NULL)
                break;
            iter = iter->next;
            steps--;
        }
        return iter->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */