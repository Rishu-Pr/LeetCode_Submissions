class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        vector<int> temp;
        vector<int> brk;
        
        for(int i = 0; i < groups.size(); i++){
            brk.push_back(temp.size()); 
            for(int x : groups[i]){
                temp.push_back(x);
            }
        }
        brk.push_back(temp.size()); 

        int idx1 = 0;
        int brkidx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(idx1 == temp.size()) break; 
            
            if(nums[i] == temp[idx1]){
                idx1++;
                if(idx1 == brk[brkidx + 1]){ 
                    brkidx++;
                }
            }
            else{
                if (idx1 > brk[brkidx]) {
                    i = i - (idx1 - brk[brkidx]); 
                }
                
                idx1 = brk[brkidx]; 
            }
        }

        return (idx1 == temp.size());
    }
};