class Solution {
public:
    char slowestKey(vector<int>& r, string k) {
        int arr[26] = {};
        int time;
        
        for(int i = 0; i < r.size(); i++){
            if(i) time = r[i] - r[i - 1];
            else time = r[i];
            
            if(time > arr[k[i] - 'a']) arr[k[i] - 'a'] = time;
        }
        
        int max = 0;
        char ans = k[0];
        
        for(int i = 25; i >= 0; i--){
            if(arr[i] > max){
                max = arr[i];
                ans = 'a' + i;
            }
        }
        
        return ans;
    }
};