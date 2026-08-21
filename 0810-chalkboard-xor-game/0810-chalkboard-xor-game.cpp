class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int total = 0;
        
        for (int x : nums) {
            total ^= x;
        }

        return total == 0 || nums.size() % 2 == 0;
    }
};