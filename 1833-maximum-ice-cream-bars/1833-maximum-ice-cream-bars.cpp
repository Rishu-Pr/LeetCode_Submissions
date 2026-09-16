class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> temp(1e5 + 1, 0);
        for(int x : costs){
            temp[x]++;
        }

        int cnt = 0;
        for(int i = 0; i < temp.size(); i++){
            if(i > coins){
                break;
            }
            while(temp[i]){
                if(i > coins){
                    break;
                }
                cnt++;
                coins -= i;
                temp[i]--;
            }
        }

        return cnt;
    }
};