class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int x = (arr.size() * 5) / 100;
        double total = 0;
        
        for(int i = x; i < arr.size() - x; i++){
            total += arr[i];
        }
        
        int y = arr.size() - x - x;
        
        return total / y;
    }
};

