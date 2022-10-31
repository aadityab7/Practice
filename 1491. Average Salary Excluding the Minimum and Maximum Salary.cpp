class Solution {
public:
    double average(vector<int>& salary) {
        long long total = 0;
        int min = INT_MAX;
        int max = 0;
        
        for(int i = 0; i < salary.size(); i++){
            total += salary[i];
            if(salary[i] > max) max = salary[i];
            if(salary[i] < min) min = salary[i];
        }
        
        total -= min;
        total -= max;
        double x = salary.size() - 2;
        
        double ans = (double) total / x;
        return ans;
    }
};