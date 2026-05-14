class BrowserHistory {
    vector<string> V;
    int top;
    int curr;
public:
    BrowserHistory(string homepage) {
        V.push_back(homepage);
        top = 0;
        curr = 0;
    }
    
    void visit(string url) {
        curr++;

        if(curr < V.size()) V[curr] = url;
        else V.push_back(url);

        top = curr;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return V[curr];
    }
    
    string forward(int steps) {
        curr = min(top , curr + steps);
        return V[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */