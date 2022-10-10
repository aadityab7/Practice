class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //judge must be trusted by all and trust no one
        int size = trust.size();
        //0 1 2
        
        vector<int> arr(n + 1, 0);
        
        for(int i = 0; i < size; i++){
            //the one who is trusting someone else can never be the judge
            arr[trust[i][0]]--;
            arr[trust[i][1]]++;
        }
        
        int ans = -1;
        
        for(int i = 1; i <= n; i++){
            if(arr[i] == n - 1) ans = i;
        }
        
        return ans;
        
    }
};