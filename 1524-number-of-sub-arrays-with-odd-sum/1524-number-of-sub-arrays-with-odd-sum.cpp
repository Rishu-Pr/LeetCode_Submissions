class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();

        long long cntOdd = 0;
        long long cntEven = 0;
        
        for (int i = 1; i < n; i++){
            arr[i] += arr[i - 1];
        }
        for(int x : arr){
            if(x % 2){
                cntOdd++;
            }
            else{
                cntEven++;
            }
        }

        return (((cntEven + 1) % MOD) * (cntOdd % MOD)) % MOD;
    }
};