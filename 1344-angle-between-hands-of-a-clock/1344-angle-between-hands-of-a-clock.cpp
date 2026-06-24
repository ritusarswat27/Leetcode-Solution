class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(30 * hour - 5.5 * minutes);
        if(angle <= 180) return angle;
        return 360 - angle;     
    }
};