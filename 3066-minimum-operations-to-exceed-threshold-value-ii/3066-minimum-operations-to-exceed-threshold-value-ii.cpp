class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(int i : nums){
            minHeap.push(i);
        }

        int opp = 0;
        while(minHeap.top() < k){
            long long a = minHeap.top(); minHeap.pop();
            long long b = minHeap.top(); minHeap.pop();

            long long val = (long long)((long long)min(a, b) * 2) + (long long)max(a, b);
            minHeap.push(val);
            opp++;
        }

        return opp;
    }
};
