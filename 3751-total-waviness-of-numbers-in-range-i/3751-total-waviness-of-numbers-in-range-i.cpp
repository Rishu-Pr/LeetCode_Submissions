class Solution {
    void solve(int num, int& ans){
        if(num < 100) return;

        string num_str = to_string(num);
        for(int i = 1; i < num_str.size() - 1; i++){
            if(num_str[i] > num_str[i + 1] && num_str[i] > num_str[i - 1]) ans++;
            if(num_str[i] < num_str[i + 1] && num_str[i] < num_str[i - 1]) ans++;
        }
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++)
            solve(i, ans);
        
        return ans;
    }
};