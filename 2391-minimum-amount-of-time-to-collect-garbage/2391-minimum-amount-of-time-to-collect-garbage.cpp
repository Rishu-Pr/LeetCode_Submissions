class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int M = 0;
        int P = 0;
        int G = 0;

        int cnt = 0;

        for(int i = 0; i < garbage.size(); i++){
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'M'){
                    M = i;
                }
                if(garbage[i][j] == 'P'){
                    P = i;
                }
                if(garbage[i][j] == 'G'){
                    G = i;
                }

            }
            cnt += garbage[i].size();
        }

        for(int i = 0; i < M; i++){
            cnt += travel[i];
        }
        for(int i = 0; i < P; i++){
            cnt += travel[i];
        }
        for(int i = 0; i < G; i++){
            cnt += travel[i];
        }

        return cnt;
    }
};