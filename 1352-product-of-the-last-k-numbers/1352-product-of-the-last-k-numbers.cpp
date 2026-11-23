class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            nums.clear();
            nums.push_back(1);
        }
        else{
            nums.push_back(num * nums.back());
        }
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if(k >= n){
            return 0;
        }
        return nums.back() / nums[n - k - 1];
    }
};
// class ProductOfNumbers {
// public:
//     vector<int> nums;
//     int maxZ = -1;
//     ProductOfNumbers() {
//         nums.push_back(1);
//     }
    
//     void add(int num) {
//         if(num == 0){
//             maxZ = nums.size();
//             nums.push_back(1);
//         }
//         else{
//             nums.push_back(num * nums.back());
//         }
//     }
    
//     int getProduct(int k) {
//         int n = nums.size();
//         if(k >= n - maxZ){
//             return 0;
//         }
//         return nums.back() / nums[n - k - 1];
//     }
// };