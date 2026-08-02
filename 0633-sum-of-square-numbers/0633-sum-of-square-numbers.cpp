class Solution {
public:
    bool judgeSquareSum(int c) {
        // 46340

        vector<long long> V(46341, 0);
        for(int i = 0; i < 46341; i++){
            V[i] = i * i;
        }

        int s = 0;
        int e = V.size() - 1;

        while(s <= e){
            if(V[s] + V[e] > c){
                e--;
            }
            else if(V[s] + V[e] < c){
                s++;
            }
            else{
                return true;
            }
        }

        return false;
    }
};