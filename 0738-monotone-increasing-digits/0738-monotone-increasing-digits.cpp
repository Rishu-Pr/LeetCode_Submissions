class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n < 10){
            return n;
        }
        vector<int> V;
        while(n){
            V.push_back(n % 10);
            n /= 10;
        }
        
        for(int i = 0; i < V.size() - 1; i++){
            if(V[i] < V[i + 1]){
                V[i] = 9;
                V[i + 1] -= 1;
                for(int j = 0; j < i; j++) {
                    V[j] = 9;
                }
            }
        }

        int ans = 0;
        for(int i = V.size() - 1; i >= 0; i--){
            ans *= 10;
            ans += V[i];
        }

        return ans;
    }
};