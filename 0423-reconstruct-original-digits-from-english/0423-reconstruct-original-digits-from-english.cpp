class Solution {
public:
    string originalDigits(string s) {
        vector<int> data(26, 0);
        vector<int> digit(10, 0);
        for(char chr : s){
            data[chr - 'a']++;
        }
        digit[0] = data[25];
        digit[2] = data[22];
        digit[4] = data[20];
        digit[6] = data[23];
        digit[8] = data[6];

        digit[1] = data[14] - digit[0] - digit[2] - digit[4];
        digit[3] = data[7] - digit[8];
        digit[5] = data[5] - digit[4];
        digit[7] = data[18] - digit[6];
        digit[9] = (data[13] - digit[1] - digit[7]) / 2;

        string ans = "";
        for(int i = 0; i < 10; i++){
            while(digit[i]){
                ans += (i + '0');
                digit[i]--;
            }
        }

        return ans;
    }
};