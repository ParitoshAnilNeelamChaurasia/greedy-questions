// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size() ;

        map<int,int> mp ;

        for(auto it : tasks)
        {
            mp[it]++ ;
        }

        int count = 0 ;
        for(auto it : mp)
        {
            if(it.second == 1)
            {
                return -1 ;
            }

            if(it.second % 3 == 0)
            {
                count += it.second/3 ;
            }
            else
            {
                count += it.second/3 + 1 ;
            }
        }
        return count ;
    }
};
