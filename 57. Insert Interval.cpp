class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0], end = newInterval[1];
        int flag = 0;

        for(auto interval : intervals){
            if(flag) ans.push_back(interval);
            else{
                //check if start lies btw 0 and 1 
                //or 0 lies between start and end
                //if so then merge the intervals
                //else if end < 0
                //push it in ans
                if((start >= interval[0] && start <= interval[1]) || (interval[0] >= start && interval[0] <= end)){
                    start = min(interval[0], start);
                    end = max(end, interval[1]);
                }
                else if(end < interval[0]){
                    ans.push_back({start, end});
                    flag = 1;
                    ans.push_back(interval);
                }
                else if(start > interval[1]){
                    ans.push_back(interval);
                }
            }    
        }

        if(flag == 0) ans.push_back({start, end});
 
        return ans;
    }
};