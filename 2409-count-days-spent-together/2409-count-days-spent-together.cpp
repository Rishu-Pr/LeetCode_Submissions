class Solution {
    int getDay(string s, vector<int>& days) {
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));
        
        return days[m - 1] + d;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int startA = getDay(arriveAlice, days);
        int endA = getDay(leaveAlice, days);
        int startB = getDay(arriveBob, days);
        int endB = getDay(leaveBob, days);
        
        int start = max(startA, startB);
        int end = min(endA, endB);
        
        if (start > end) return 0;
        
        return end - start + 1;
    }
};