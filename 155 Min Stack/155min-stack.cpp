class MinStack {
    vector<int> V;
    int top_elem;

public:
    MinStack() {
        top_elem = -1;
    }

    void push(int val) {
        V.push_back(val);
        top_elem++;
    }

    void pop() {
        if (top_elem == -1)
            return;

        V.pop_back();
        top_elem--;
    }

    int top() { return V[top_elem]; }

    int getMin() {
        int min = INT_MAX;
        for (int x : V) {
            if (min > x) {
                min = x;
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */