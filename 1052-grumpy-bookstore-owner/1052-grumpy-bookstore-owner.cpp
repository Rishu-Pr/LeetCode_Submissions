class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = grumpy.size();
        for(int i = 0; i < n; i++){
            if(grumpy[i]){
                sum += customers[i];
            }
        }

        int left = 0;
        int right = minutes - 1;

        int temp = 0;
        for(int i = 0; i < minutes; i++){
            if(!grumpy[i]){
                temp += customers[i];
            }
        }
        int maxS  = temp;

        while(right < n - 1){
            if(!grumpy[left]){
                temp -= customers[left];
            }
            left++;
            if(!grumpy[right]){
                temp += customers[right];
            }
            right++;
            maxS = max(maxS, temp);
        }

        return sum + maxS;
    }
};