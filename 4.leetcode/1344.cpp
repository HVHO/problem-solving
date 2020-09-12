//1344. Angle Between Hands of a Clock

#include<algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourf = 30*hour;
        hourf += 30*(minutes/60.0);
        double minutesf = 6*minutes;
        
        return min(abs(hourf-minutesf),360-abs(hourf-minutesf));
        
    }
};