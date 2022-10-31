class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int i, j, k, x, y, z;
        int ans = 0;
        
        for(i = 0; i < arr.size() - 2; i++){
            for(j = i + 1; j < arr.size() - 1; j++){
                if(abs(arr[j] - arr[i]) <= a){
                    for(k = j + 1; k < arr.size(); k++){
                        y = abs(arr[j] - arr[k]);
                        z = abs(arr[k] - arr[i]);

                        if(y <= b && z <= c) ans++;
                    }
                }
                
            }
        }
        
        return ans;
    }
};