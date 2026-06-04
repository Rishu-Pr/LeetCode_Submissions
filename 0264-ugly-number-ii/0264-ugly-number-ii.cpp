class Solution {
public:    
    int nthUglyNumber(int n) {
        vector<int> V = {1};
        
        int ptr_2 = 0;
        int ptr_3 = 0;
        int ptr_5 = 0;

        while(V.size() < n){
            int Val_2 = V[ptr_2] * 2;
            int Val_3 = V[ptr_3] * 3;
            int Val_5 = V[ptr_5] * 5;

            int minV = min(Val_2, min(Val_3, Val_5));
            V.push_back(minV);

            if(minV == Val_2) ptr_2++;
            if(minV == Val_3) ptr_3++;
            if(minV == Val_5) ptr_5++;
        }

        return V[n - 1];
    }
};