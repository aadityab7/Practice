class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int prev_end = timeSeries[0];
        int ans = 0;
        //ans = timeSeries.size() * duration;
        
        
        for(int i = 0; i < timeSeries.size(); i++){
            
            ans += duration;
            
            if(timeSeries[i] < prev_end){
                ans -= (prev_end - timeSeries[i]);
            }
            
            prev_end = timeSeries[i] + duration;
        }
        
        return ans;
        
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int prev_end = timeSeries[0];
        long ans = 0;
        ans = timeSeries.size() * duration;
        
        
        for(int i = 0; i < timeSeries.size(); i++){
            
//             ans += duration;
            
            if(timeSeries[i] < prev_end){
                ans = ans - (prev_end - timeSeries[i]);
            }
            
            prev_end = timeSeries[i] + duration;
        }
        
        return (int)ans;
        
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long n = timeSeries.size();
        long ans = n * duration;
        
        for(int i = 1; i < n; i++){
            
            if(timeSeries[i] < (timeSeries[i - 1] + duration)){
                ans -= (timeSeries[i - 1] + duration - timeSeries[i]);
            }
            
        }
        
        return (int)ans;
        
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        
        for(int i = 0; i < timeSeries.size() - 1; i++){
            if(timeSeries[i + 1] - timeSeries[i] < duration){
                ans += timeSeries[i + 1] - timeSeries[i];
            }
            else{
                ans += duration;
            }
        }
        
        return ans + duration;
        
    }
};