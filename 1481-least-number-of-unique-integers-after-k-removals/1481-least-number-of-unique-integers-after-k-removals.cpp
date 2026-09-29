class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for(int i : arr){
            map[i]++;
        }
        vector<int> freq;
        for (auto const& p : map) {
            freq.push_back(p.second);
        }
        sort(freq.begin(), freq.end());

        int cnt = freq.size();
        for(int i : freq){
            if(i <= k){
                cnt--;
                k -= i;
            }
            else{
                break;
            }
        }

        return cnt;
    }
};