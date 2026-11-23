class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        int prd = 1;
        for(int i = 0; i < k; i++){
            prd *= nums[n - i - 1];
        }
        return prd;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */