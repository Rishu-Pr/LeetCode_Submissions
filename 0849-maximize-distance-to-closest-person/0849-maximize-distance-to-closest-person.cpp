class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxV = 0;
        int cnt = 0;
        int strt = 0;
        while(seats[strt] != 1){
            cnt++;
            strt++;
        }
        maxV = cnt;
        cnt = 0;
        for(int i = strt; i < seats.size(); i++){
            if(seats[i] == 0){
                cnt++;
            }
            else{
                maxV = max(maxV, (cnt + 1) / 2);
                cnt = 0;
            }
        }

        return max(cnt, maxV);
    }
};