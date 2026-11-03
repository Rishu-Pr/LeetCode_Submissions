class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multimap<int, int> map;
        for(int i : arr){
            map.insert({abs(i - x), i});
        }
        // vector<pair<int, int>> vec(map.begin(), map.end());

        // sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        //     return a.first < b.first;
        // });
        vector<int> ans;
        for(auto& [K,V] : map){
            if(!k){
                break;
            }
            ans.push_back(V);
            k--;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};