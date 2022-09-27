class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int arr[52] = {};
        
        for(int i = 0; i < jewels.size(); i++){
            if(jewels[i] >= 'a' && jewels[i] <= 'z'){
                arr[jewels[i] - 'a'] = 1;
            }
            else{
                arr[jewels[i] - 'A' + 26] = 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] >= 'a' && stones[i] <= 'z'){
                if(arr[stones[i] - 'a']){
                    ans++;
                }
            }
            else{
                if(arr[stones[i] - 'A' + 26]){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};