// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size() ;

        vector<pair<int,pair<int,int>>> ans ;

        for(int i = 0 ; i < n ; ++i)
        {
            ans.push_back({capacity[i] - rocks[i] , {capacity[i] , rocks[i]}}) ;
        }

        sort(ans.begin() , ans.end()) ;

        int count = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(ans[i].first == 0)
            {
                count++ ;
            }
            else
            {
                if(additionalRocks >= ans[i].first)
                {
                additionalRocks = additionalRocks - ans[i].first ;
                count++ ;
                }
                else
                {
                    break ;
                }
            }
        }
        return count ;
    }
};
