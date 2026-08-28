class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n;
        
        while(l < r){
            int mid = (r + l) / 2;
            int count = 0;
            for(int i = 1; i <= m; i++){
                count += min(n, mid / i);
            }

            if(count >= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        return l;
    }
};