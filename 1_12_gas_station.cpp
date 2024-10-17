// https://leetcode.com/problems/gas-station/description/

// Brute force

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ;
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(gas[i] < cost[i])
            {
                continue ;
            }

            int j = (i+1) % n ;

            int cost_for_moving_from_this_station = cost[i] ;

            int gas_earn_from_next_station = gas[j] ;

            int curr_gas = gas[i] - cost_for_moving_from_this_station + gas_earn_from_next_station ;

            while(j != i)
            {
                if(curr_gas < cost[j])
                {
                    break ;
                }

                int cost_for_moving_from_this_j = cost[j] ;

                j = (j+1) % n ;

                int gas_earned_in_next_station = gas[j] ;

                curr_gas = curr_gas - cost_for_moving_from_this_j + gas_earned_in_next_station ;
            }

            if(j == i)
            {
                return i ;
            }
        }
        return -1 ;
    }
};

// Greedy -> O(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ;

        int gas_earn = accumulate(gas.begin() , gas.end() , 0) ;

        int cost_loss = accumulate(cost.begin() , cost.end() , 0) ;

        if(gas_earn < cost_loss)
        return -1 ;

        int tot = 0 ;
        int ans = 0 ;

        for(int i = 0 ; i < n ; ++i)
        {
            tot = tot + gas[i] - cost[i] ;

            if(tot < 0)
            {
                tot = 0 ;
                ans = i+1 ;
            }
        }   
        return ans ;
    }
};
