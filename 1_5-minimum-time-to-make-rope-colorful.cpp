// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size() ;

        int time = 0 ;
        int prev_mx = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(i > 0 && colors[i] != colors[i-1])
            {
                prev_mx = 0 ;
            }

            int curr = neededTime[i] ;

            time += min(prev_mx , curr) ;

            prev_mx = max(prev_mx , curr) ;
        }
        return time ;
    }
};
