class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> map;
        long long days = 0;
        for(int i : tasks){
            if(!map.count(i)){
                days++;
            }
            else{
                if(days - map[i] <= space){
                    int x = days - map[i];
                    days += space - x + 1;
                }
                else{
                    days++;
                }
            }
            map[i] = days;
        }

        return days;
    }
};