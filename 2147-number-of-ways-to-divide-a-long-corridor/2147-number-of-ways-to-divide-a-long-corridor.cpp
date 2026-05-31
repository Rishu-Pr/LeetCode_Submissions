#define MOD 1000000007
class Solution {
    int solve(vector<int>& seats, int idx){
        if(idx == seats.size()) return 1;
        if(idx >= seats.size() - 1) return 0;

        if(idx + 2 < seats.size()) {
            long long gap = (seats[idx + 2] - seats[idx + 1]) % MOD;
            return (gap * (solve(seats, idx + 2) % MOD)) % MOD;
        }
        return 1;
    }
public:
    int numberOfWays(string corridor) {
        vector<int> seats;
        for(int i = 0; i < corridor.size(); i++)
            if(corridor[i] == 'S') seats.push_back(i);
        
        if(seats.size() % 2 || seats.size() == 0) return 0;
        return solve(seats, 0);
    }
};