class Solution {
    int reverseInt(int x){
        int y = 0;
        while(x){
            y *= 10;
            y += x % 10;
            x /= 10;
        }

        return y;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums.push_back(reverseInt(nums[i]));
        }

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        return nums.size();
    }
};