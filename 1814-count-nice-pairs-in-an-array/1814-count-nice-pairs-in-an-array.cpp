class Solution {
    int revX(int x){
        int v = 0;
        while(x){
            v *= 10;
            v += (x % 10);
            x /= 10;
        }

        return v;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int cnt = 0;

        unordered_map<int, int> map;
        for(int x : nums){
            map[x - revX(x)]++;
        }

        for(auto const& [k, v] : map){
            cnt += (v * 1ll * (v - 1) / 2) % MOD;
        }

        return cnt % MOD;
    }
};