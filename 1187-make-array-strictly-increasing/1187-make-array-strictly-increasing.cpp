class Solution {
    map<pair<int, int>, int> dp;
    int solve(vector<int>& arr1, vector<int>& arr2, int idx, int prev){
        if(idx == arr1.size()) return 0;
        if (dp.find({idx, prev}) != dp.end()) return dp[{idx, prev}];
        
        int skip = 1e7;
        int replace = 1e7;

        if (arr1[idx] > prev) {
            skip = solve(arr1, arr2, idx + 1, arr1[idx]); // The current element becomes the new 'prev'
        }
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            replace = 1 + solve(arr1, arr2, idx + 1, *it); 
        }

        return dp[{idx, prev}] = min(skip, replace);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        // Remove Duplicates!
        auto it = unique(arr2.begin(), arr2.end());
        arr2.erase(it, arr2.end());
        int ans = solve(arr1, arr2, 0, -1);
        return (ans >= 1e7) ? -1 : ans;
    }
};