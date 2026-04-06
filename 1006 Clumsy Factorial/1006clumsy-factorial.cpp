class Solution {
public:
    int clumsy(int n) {
        if(n == 3) return 6;
        else if(n == 2) return 2;
        else if(n == 1) return 1;

        int ans = n*(n-1)/(n-2)+(n-3);

        for(int i = n-4; i>0; i -= 4){
            if(i < 4){
                if(i == 3) return ans - 6;
                else if(i == 2) return ans - 2;
                else return ans - 1;
            }

            ans = ans - i * (i - 1) / (i - 2) + (i - 3);
        }
        return ans;
    }
};