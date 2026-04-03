class FrontMiddleBackQueue {
    vector<int> V;
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        V.insert(V.begin(),val);
    }
    
    void pushMiddle(int val) {
        int mid = V.size()/2;
        V.insert(V.begin()+mid,val);
    }
    
    void pushBack(int val) {
        V.push_back(val);
    }
    
    int popFront() {
        if(V.empty()) return -1;
        int val = V.front();
        V.erase(V.begin());
        return val;
    }
    
    int popMiddle() {
        if(V.empty()) return -1;
        int mid = (V.size()-1)/2;
        int val = V[mid];
        V.erase(V.begin() + mid);
        return val;
    }
    
    int popBack() {
        if(V.empty()) return -1;
        int val = V.back();
        V.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */