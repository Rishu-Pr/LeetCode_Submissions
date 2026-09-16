class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        long long ans = 2 * n;
        int t = 0;
        bool t1 = 0;
        bool t2 = 0;
        bool t3 = 0;
        for(int i = 0; i < reservedSeats.size(); i++){
            if(t != reservedSeats[i][0]){
                if(!t1 && !t3){
                    ans -= 0;
                }
                else if(!t1 || !t2 || !t3){
                    ans -= 1;
                }
                else{
                    ans -= 2;
                }
                t1 = 0;
                t2 = 0;
                t3 = 0;
                t = reservedSeats[i][0];
            }
            if(reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5){
                t1 = true;
            }
            if(reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 7){
                t2 = true;
            }
            if(reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9){
                t3 = true;
            }
        }

        if(!t1 && !t3){
            ans -= 0;
        }
        else if(!t1 || !t2 || !t3){
            ans -= 1;
        }
        else{
            ans -= 2;
        }

        return ans;
    }
};