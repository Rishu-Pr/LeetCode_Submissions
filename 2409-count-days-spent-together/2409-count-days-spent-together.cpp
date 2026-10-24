class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        vector<int> prefix(13, 0);
        for (int i = 0; i < 12; i++) {
            prefix[i + 1] = prefix[i] + days[i];
        }

        auto dayOfYear = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            return prefix[month - 1] + day;
        };

        int start = max(dayOfYear(arriveAlice),dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice),dayOfYear(leaveBob));

        return max(0, end - start + 1);
    }
};