class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int minOps = n;
        bool hasZero = false;

        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '0') hasZero = true;
            
            for (int j = i - 1; j >= 0; j--) {
                if ((num[i] == '0' && num[j] == '0') || 
                    (num[i] == '5' && num[j] == '2') || 
                    (num[i] == '0' && num[j] == '5') || 
                    (num[i] == '5' && num[j] == '7')) {
                    
                    int ops = (i - j - 1) + (n - 1 - i);
                    minOps = min(minOps, ops);
                }
            }
        }

        if (minOps == n && hasZero) {
            return n - 1;
        }

        return minOps;
    }
};