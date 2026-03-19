class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int idx = 0;
        int isNeg = 0;
        int n = s.size();

        while (idx < n && s[idx] == ' ')
            idx++;

        if (s[idx] == '-') {
            isNeg = 1;
            idx++;
        } else if (s[idx] == '+')
            idx++;

        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            ans = ans * 10 + (s[idx++] - '0');
            if (ans > INT_MAX) {
                if (isNeg) return INT_MIN;
                else return INT_MAX;
            }
        }
        if (isNeg)
            ans *= -1;

        return ans;
    }
};