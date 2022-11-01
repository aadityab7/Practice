class Solution {
    //0 0 0 0 0 0 0 0 
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> arr((n + 1), 0);
        int j = rounds[0];
        int end;
        
        for(int i = 1; i < rounds.size(); i++){
            //cout << i << ' ';
            end = rounds[i];
            
            //go from start to end and arr[j]++
            
            while(j != end){
                //cout << j << ' ';
                arr[j]++;
                j++;
                if(j == (n + 1)) j = 1;
            }
            
            arr[j]++;
            j++;
            if(j == (n + 1)) j = 1;
            
            //cout << arr[1] << ' ' << arr[2] << '\n';
        }
        
        
        int max = 0;
        for(int i = 1; i <= n; i++){
            if(arr[i] > max) max = arr[i];
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            if(arr[i] == max) ans.push_back(i);
        }
        
        return ans;
    }
};