class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        long long sum = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            sum += shifts[i];
            int n=sum%26;
            if ('z' - s[i] < n)
                s[i] = 'a' + (n - 1 - ('z' - s[i]));
            else
                s[i] += n;
        }

        return s;
    }
};