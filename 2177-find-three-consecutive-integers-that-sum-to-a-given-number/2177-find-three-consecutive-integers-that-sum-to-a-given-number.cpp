class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> V;
        if(!(num % 3)){
            long long x = num / 3;
            V.push_back(x - 1);
            V.push_back(x);
            V.push_back(x + 1);
        }

        return V;
    }
};