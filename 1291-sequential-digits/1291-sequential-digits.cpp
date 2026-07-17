class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        if(high < low) return ans;
        int n = low;
        int firstNum = 0;
        int firstAdd = 0;
        int digit = 1;
        while(low > 0){
            firstNum = (firstNum * 10) + (digit++);
            firstAdd = (firstAdd * 10) + 1;
            low /= 10;
        }

        while(firstNum <= high){
            int curr = firstNum;
            while(curr % 10 != 9){
                if(curr > high){
                    break;
                }
                if(curr >= n) ans.push_back(curr);
                curr += firstAdd;
            }

            if(curr <= high){
                if (curr >= n) ans.push_back(curr);
            }

            firstNum = (firstNum * 10) + (digit++);
            firstAdd = (firstAdd * 10) + 1;
            
        }
        if(!ans.empty() && ans.back() > high){
            ans.pop_back();
        }
        
        return ans;
    }
};