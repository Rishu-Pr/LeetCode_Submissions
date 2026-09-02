class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> V;
        int l = 1;
        int r = n;
        if(k == 1){
            for(int i = 1; i <= n; i++){
                V.push_back(i);
            }
            return V;
        }

        V.push_back(l++);
        while(k > 1){
            V.push_back(r--);
            k--;
            if(k > 1){
                V.push_back(l++);
                k--;
            }
        }
        if(V.back() == r + 1){
            while(r >= l){
                V.push_back(r--);
            }
        }else if(V.back() == l - 1){
            while(r >= l){
                V.push_back(l++);
            }
        }

        return V;
    }
};