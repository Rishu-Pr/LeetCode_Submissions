class Solution {
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        srand(time(0));
        int sum = 0;
        for(int x : w){
            sum += x;
            prefix.push_back(sum);
        }
    }
    
    int pickIndex() {
        int randomNum = (rand() % prefix.back()) + 1;
        auto ittr = lower_bound(prefix.begin(), prefix.end(), randomNum);
        
        return ittr - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */