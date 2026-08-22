class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int> digits;
        int orig = n;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        int sum = 0;
        int prd = 1;
        for(int x : digits){
            sum += x;
            prd *= x;
        }

        return (orig % (sum + prd)) ? false : true;
    }
};