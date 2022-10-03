class Solution {
private:
    int get_best(int curr, vector<int> &arr, vector<int> &dp){
        
        if(curr < 0) return 0;
        if(curr == 0 || curr == 1) return arr[curr];
        
        if(dp[curr]) return dp[curr];
    
        int x = get_best(curr - 1, arr, dp);
        int y = get_best(curr - 2, arr, dp);
    
        dp[curr] = min(x,y) + arr[curr];
        return dp[curr];
    }
    
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //this is a recursion and greedy problem
        int n = cost.size();
        vector<int> dp(n, 0);
        
        int x = get_best(n - 1, cost, dp);
        int y = get_best(n - 2, cost, dp);
        if(x < y) return x;
        
        return y;
    }
};

/*
0
1
2
3

get
best of curr and best of curr + 1
recursively 
end condition if i == size - 1 or i == size - 2;
return arr[i]
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //this is a dynamic programming problem 
        int n = cost.size();
        vector<int> dp = cost;
        
        for(int i = 0; i < n; i++){
            if(i > 1) dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
we have to get to last step so we are calc the cheapest of costs to up there
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //this is a dynamic programming problem 
        int n = cost.size();
        int f = cost[0], s = cost[1];
        
        for(int i = 2; i < n; i++){
            //to get to this step is it better to take the first or sec step
            int curr = cost[i] + min(f,s);
            f = s;
            s = curr;
        }
        
        return min(f, s);
    }
};

/*
we have to get to last step so we are calc the cheapest of costs to up there
*/