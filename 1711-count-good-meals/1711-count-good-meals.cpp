#define MOD 1000000007
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> req_sum;
        int i = 1;
        req_sum.push_back(i);
        for(int j = 0; j < 21; j++){
            i *= 2;
            req_sum.push_back(i);
        }
        unordered_map<int, long long> map;
        for(int x : deliciousness){
            map[x]++;
        }

        long long cnt = 0;
        for(auto p : map){
            for(int x : req_sum){
                if(p.first == (x - p.first)){
                    cnt = (cnt + (p.second * (p.second - 1) / 2)) % MOD;
                }
                else if (p.first < (x - p.first) && map.count(x - p.first)){
                    cnt = (cnt + p.second * map[x - p.first]) % MOD;
                }
            }
        }

        return cnt % MOD;
    }
};