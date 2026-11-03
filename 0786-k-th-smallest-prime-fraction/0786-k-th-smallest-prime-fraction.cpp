class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<pair<double, pair<int, int>>> vec;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                vec.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }

        sort(vec.begin(), vec.end());
        return {vec[k - 1].second.first, vec[k - 1].second.second};
    }
};