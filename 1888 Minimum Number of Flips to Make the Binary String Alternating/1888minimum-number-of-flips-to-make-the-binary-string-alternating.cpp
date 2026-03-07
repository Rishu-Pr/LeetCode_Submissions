class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;
        
        string alt1, alt2;
        for (int i = 0; i < 2*n; i++) {
            alt1 += (i % 2 == 0 ? '0' : '1');
            alt2 += (i % 2 == 0 ? '1' : '0');
        }
        
        int res = n, diff1 = 0, diff2 = 0;
        int left = 0;

        for(int i = 0;i<2*n;i++){
            if (t[i]!=alt1[i]) diff1++;
            if (t[i]!=alt2[i]) diff2++;

            if(i-left+1>n) {
                if (t[left]!=alt1[left]) diff1--;
                if (t[left]!=alt2[left]) diff2--;
                left++;
            }
            if(i-left+1==n)
                res = min(res,min(diff1,diff2));
        }
        return res;
    }
};