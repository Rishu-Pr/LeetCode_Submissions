class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> kArr(k, 0);
        for(int i : arr){
            while(i < 0){
                i += k;
            }
            kArr[i % k]++;
        }

        if(kArr[0] % 2){
            return false;
        }
        if((k % 2 == 0) && (kArr[k / 2] % 2)){
            return false;
        }

        for(int i = 1; i <= k / 2; i++){
            if(kArr[i] != kArr[k - i]){
                return false;
            }
        }

        return true;
    }
};