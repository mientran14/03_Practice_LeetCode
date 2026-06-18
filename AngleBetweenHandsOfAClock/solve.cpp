class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 360/60 = 6
        double minuteAngle = minutes * 6;

        // 360/12 = 30
        // 30/60 = 0.5
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;

        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360 - angle);
    }
};