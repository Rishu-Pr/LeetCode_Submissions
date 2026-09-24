class Solution {
    int convoSingle(int x){
        if(x < 10){
            return x;
        }
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(convoSingle(nums[i]) == i){
                return i;
            }
        }

        return -1;
    }
};