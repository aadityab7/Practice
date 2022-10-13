class Solution {
public:
    int nthUglyNumber(int n) {
        //dynamic programming
        
        if(n == 1) return 1;
        
        vector<int> arr(n);
        arr[0] = 1;
        
        //pointers to the prev values for which we have calculated
        //2, 3 and 5 multiples;
        
        int t = 0, th = 0, f = 0;
        
        for(int i = 1; i < n; i++){
            
            arr[i] = min(arr[t] * 2, min(arr[th] * 3, arr[f] * 5));
            
            if(arr[i] == arr[t] * 2) t++;
            if(arr[i] == arr[th] * 3) th++;
            if(arr[i] == arr[f] * 5) f++;

        }
        
        return arr[n - 1];
    }
};