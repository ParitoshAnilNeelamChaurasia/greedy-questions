// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = growTime.size() ;

        vector<pair<int,int>> ans ;

        for(int i = 0 ; i < n ; ++i)
        {
            ans.push_back({plantTime[i] , growTime[i]}) ;
        }

        auto lambda = [](pair<int,int> &p1, pair<int,int> &p2){
                return p1.second > p2.second ;
        };
        sort(ans.begin() , ans.end() , lambda) ;

        int max_bloom_time = 0 ;
        int prev_plant_time = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            int curr_plant_time = ans[i].first ;
            int curr_grow_time = ans[i].second ;

            prev_plant_time += curr_plant_time ;

            int curr_bloom_time = prev_plant_time + curr_grow_time ;

            max_bloom_time = max(max_bloom_time , curr_bloom_time) ;
        }
        return max_bloom_time ;  
    }
};
