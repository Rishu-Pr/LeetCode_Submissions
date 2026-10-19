class Solution {
    void pFact(int n, unordered_map<int, int>& map){
        if(n % 2 == 0){
            map[2]++;
        }
        while(n % 2 == 0){
            n /= 2;
        }
        for(int i = 3; i <= sqrt(n); i++){
            if(n % i == 0){
                map[i]++;
            }
            while(n % i == 0){
                n /= i;
            }
        }
        if(n > 2){
            map[n]++;
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int x : nums){
            pFact(x, map);
        }
        return map.size();
    }
};