class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumArray = 0;
        for(int i = 0; i < gas.size(); i++){
            cost[i] = gas[i] - cost[i];
            sumArray += cost[i];
        }
        if(sumArray < 0){
            return -1;
        }
        int idx = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += cost[i];
            if(sum < 0){
                sum = 0;
                idx = i + 1;
            }
        }

        return idx;
    }
};