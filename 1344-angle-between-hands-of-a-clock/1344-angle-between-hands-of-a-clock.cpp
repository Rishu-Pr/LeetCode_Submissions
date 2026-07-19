class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;

        int hour_deg = hour * 30;
        double deg = 0.5 * minutes;

        int in_deg = minutes * 6;

        double ttl = abs(hour_deg + deg - in_deg);

        if (ttl > 180){
            ttl = abs(360 - ttl);
        }
        return ttl;
    }
};