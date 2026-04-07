class CustomStack {
    int arr[1000];
    int max_size;
    int size;
    int top;
public:
    CustomStack(int maxSize) {
        size = 0;
        max_size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(size != max_size){
            arr[(++top) % max_size] = x;
            size++;
        }
    }
    
    int pop() {
        if(size == 0) return -1;
        
        int val = arr[top--];
        size--;
        return val;
    }
    
    void increment(int k, int val) {
        if(k > size){
            for(int i = 0; i < size; i++){
                arr[i] += val;
            }
        }
        else{
            for(int i = 0; i < k; i++){
                arr[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */