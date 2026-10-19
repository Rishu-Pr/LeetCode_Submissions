class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        vector<int> pref(arr.size() + 1, 0);
        for(int i = 0; i < arr.size(); i++){
            pref[i + 1] = pref[i] ^ arr[i];
        }

        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j <= arr.size(); j++){
                if(pref[i] == pref[j]){
                    cnt += (j - i - 1);
                }
            }
        }

        return cnt;
    }
};