class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        int i=1;
        while(i<=a){
            if(!(a%i) && !(b%i)) cnt++;

            i++;
        }

        return cnt;
    }
};