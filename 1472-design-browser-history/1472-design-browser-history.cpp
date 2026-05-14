class BrowserHistory {
    stack<string> perma;
    stack<string> temp;
public:
    BrowserHistory(string homepage) {
        perma.push(homepage);
    }
    
    void visit(string url) {
        perma.push(url);
        while(!temp.empty()) temp.pop();
    }
    
    string back(int steps) {
        while(steps && perma.size() > 1){
            temp.push(perma.top());
            perma.pop();
            steps--;
        }
        return perma.top();
    }
    
    string forward(int steps) {
        while(steps && !temp.empty()){
            perma.push(temp.top());
            temp.pop();
            steps--;
        }
        return perma.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */