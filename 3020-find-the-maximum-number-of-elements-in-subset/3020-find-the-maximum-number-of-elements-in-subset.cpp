class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> V;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] == 1){
                V.push_back(nums[i]);
            }
        }

        sort(V.begin(), V.end());

        int ans = 1;
        if(map.count(1)){
            int len = map[1];
            if(len % 2 == 0){
                len--;
            }

            ans = max(ans, len);
        }
        for(int i = 0; i < V.size(); i++){
            if(V[i] == 1) continue;
            long long elem = V[i];
            int curr_len = 0;

            while(elem <= 1e9 && map[elem] >= 2){
                curr_len += 2;
                elem *= elem;
            }
            if(map[elem] == 1){
                curr_len += 1;
            }
            else{
                curr_len--;
            }
            ans = max(ans, curr_len);
        }

        return ans;
    }
};