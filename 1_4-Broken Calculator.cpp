// https://leetcode.com/problems/broken-calculator/description/

class Solution {
public:
    int brokenCalc(int startValue, int target) {

        if(startValue >= target)
        return abs(startValue - target) ;
        // if target >= startvalue -> target = target/2 if target == even   

        if(target % 2 == 0)
        {
            return 1 + brokenCalc(startValue , target/2) ;
        }

        return 1 + brokenCalc(startValue , target+1) ;
    }
};
