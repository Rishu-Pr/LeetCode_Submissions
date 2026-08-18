class Solution {
public:
    vector<int> V;
    Solution(vector<int>& nums) {
        V = nums;    
    }
    
    int pick(int target) {
        vector<int> temp;
        for(int i = 0; i < V.size(); i++){
            if(V[i] == target){
                temp.push_back(i);
            }
        }

        int ranN = rand() % temp.size();

        return temp[ranN];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */