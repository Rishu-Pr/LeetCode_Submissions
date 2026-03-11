class MyQueue {
public:
#define MAX 50
    int s1[MAX], s2[MAX];
    int top1, top2;
    MyQueue() { top1 = -1, top2 = -1; }

    void push(int x) {
        if (top1 == MAX - 1 && top2 == MAX - 1)
            return;
        s1[++top1] = x;
    }

    int pop() {
        if (empty())
            return -1;

        if (top2 == -1)
            while (top1 != -1)
                s2[++top2] = s1[top1--];

        return s2[top2--];
    }

    int peek() {
        if (empty())
            return -1;

        if (top2 == -1)
            while (top1 != -1)
                s2[++top2] = s1[top1--];

        return s2[top2];
    }

    bool empty() { return (top1 == -1 && top2 == -1); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */