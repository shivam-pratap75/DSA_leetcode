class Solution {
public:
    double angleClock(int hour, int minutes) {

        
        double mini=minutes*6;
        hour=hour%12;
        hour=hour*30;
        double result=hour+mini/12;
        
        result=abs(result-mini);
        return min(result,360-result);
        
    }
};