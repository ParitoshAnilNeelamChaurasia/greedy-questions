// https://leetcode.com/problems/bag-of-tokens/description/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size() ;

        int max_score = 0 ;

        sort(tokens.begin() , tokens.end()) ;

        int ans = 0 ;

        int i = 0 ; int j = n-1 ;

        while(i <= j)
        {
            if(power >= tokens[i])
            {
                power = power - tokens[i] ;
                ans++ ;
                i++ ;
                
                max_score = max(max_score , ans) ;
            }

            else if(ans >= 1)
            {
                power += tokens[j] ;
                ans-- ;
                j-- ;
            }

            else
            return max_score ;
        }

        return max_score ;
    }
};
