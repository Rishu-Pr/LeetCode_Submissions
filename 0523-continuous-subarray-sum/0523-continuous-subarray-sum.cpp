class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2){
            return false;
        }
        vector<int> V = {0};
        for(int i = 0; i < nums.size(); i++){
            V.push_back(V.back() + nums[i]);
        }

        for(int i = 0; i < V.size(); i++){
            V[i] %= k;
        }

        unordered_map<int, int> map;
        for(int i = 0; i < V.size(); i++){
            if(map.count(V[i]) && i - map[V[i]] > 1){
                return true;
            }
            else if(!map.count(V[i])) map[V[i]] = i;
        }

        return false;
    }
};