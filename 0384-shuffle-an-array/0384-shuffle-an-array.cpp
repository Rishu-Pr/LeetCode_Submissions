class Solution {
public:
    vector<int> V;
    vector<int> orig;
    Solution(vector<int>& nums) {
        V = nums;
        orig = nums;
    }
    
    vector<int> reset() {
        V = orig;
        return V;
    }
    
    vector<int> shuffle() {
        random_device ran_div;
        mt19937 g(ran_div());
        std::shuffle(V.begin(), V.end(), g);

        return V;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */