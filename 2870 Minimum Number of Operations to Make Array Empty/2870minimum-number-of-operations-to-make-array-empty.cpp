class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int opp=0;
        for(int i=0;i<nums.size();i++){
            int count = 1;
            while(i+1<nums.size() && nums[i]==nums[i+1]){ count++;i++;}

            if(count==1) return -1;
            if(count%3==0) opp += count/3;
            else{
                while(count>4){
                    opp++;
                    count-=3;
                }
                opp += count/2;
            }
        }
        return opp;
    }
};