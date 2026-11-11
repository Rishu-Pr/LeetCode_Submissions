class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(cost1 + cost2 > costBoth){
            int minV = min(need1 , need2);
            ans += 1ll * costBoth * minV;
            need1 -= minV;
            need2 -= minV;

            if(need1){
                ans += 1ll * need1 * min(costBoth, cost1);
            }
            else if(need2){
                ans += 1ll * need2 * min(costBoth, cost2);
            }
        }
        else{
            ans += 1ll * need1 * cost1 + 1ll * need2 * cost2;
        }

        return ans;
    }
};