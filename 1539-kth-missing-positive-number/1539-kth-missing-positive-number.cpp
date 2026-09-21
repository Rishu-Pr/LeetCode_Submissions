class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int idx = 0;
        while(idx < arr.size() && k){
            i++;
            if(i == arr[idx]){
                idx++;
            }
            else{
                k--;
            }
        }
        if(k){
            i += k;
        }

        return i;
    }
};