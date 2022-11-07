class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> arr(n + 1);
        
        int max = 1;
        
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int x = i / 2;
            arr[i] = arr[x];
            if(i % 2) arr[i] += arr[x + 1];
        
            if(arr[i] > max) max = arr[i];
        }
        
        return max;
        
    }
};


/*
0 0
1 1
2 1 
3 2
4 1 
5 3
6 2
7 3 
8 1
9 4
10 1 
11 5
12 1 
13 5 
14 1 
15 4
16 1



*/