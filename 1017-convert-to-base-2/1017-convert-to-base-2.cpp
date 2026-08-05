class Solution {
    void solve(vector<long long>& V, long long n, string& ans, string temp, int idx){
        if(n == 0){ 
            ans = temp;
            return;
        }
        
        if(idx >= V.size() - 1){
            return;
        }

        if (n % V[idx + 1] != 0) {
            solve(V, n - V[idx], ans, "1" + temp, idx + 1);
        } 
        else{
            solve(V, n, ans, "0" + temp, idx + 1);
        }
    }
public:
    string baseNeg2(int n){
        if (n == 0) return "0";
        
        vector<long long> V;
        long long num = 1;
        for(int i = 0; i < 33; i++){
            V.push_back(num);
            num *= -2;
        }

        string ans = "";
        string temp = "";
        solve(V, n, ans, temp, 0);

        return ans;
    }
};