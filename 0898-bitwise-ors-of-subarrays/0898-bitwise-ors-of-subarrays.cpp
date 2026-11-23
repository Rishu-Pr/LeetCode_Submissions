class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;

        for(int x : arr){
            unordered_set<int> curr;
            curr.insert(x);

            for(int y : prev){
                curr.insert(y | x);
            }

            for(int y : curr){
                ans.insert(y);
            }

            prev = curr;
        }

        return ans.size();
    }
};