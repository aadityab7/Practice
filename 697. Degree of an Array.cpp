class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // map< int, map<pair<int, int> , int> > mp;
        //create a 2D array of size
        //or map with vector associated with it
        
        map<int, vector<int>> mp;
        
        //start end freq and element
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i + 1;
                
            }
            else{
                mp[nums[i]] = {1, i, i + 1};
            }
        }
        
        int max = 0;
        int ans = INT_MAX;
        
        // for(auto itr = mp.begin(); itr != mp.end(); itr++){
        //     vector<int> temp = itr -> second;
        //     for(int j = 0; j < 3; j++) cout << temp[j] << ' ';
        //     cout << '\n';
        // }
        
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> temp = itr -> second;
            
            if(temp[0] > max){
                max = temp[0];
                ans = temp[2] - temp[1];       
            }
            else if(temp[0] == max){
                if(temp[2] - temp[1] < ans){
                    ans = temp[2] - temp[1];
                }   
            }
            
        }
        
        return ans;
        
       
    }
};

//USE THE UNORDERED MAP
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // map< int, map<pair<int, int> , int> > mp;
        //create a 2D array of size
        //or map with vector associated with it
        
        unordered_map<int, vector<int>> mp;
        
        //start end freq and element
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i + 1;
            }
            else{
                mp[nums[i]] = {1, i, i + 1};
            }
        }
        
        int max = 0;
        int ans = INT_MAX;
        
        // for(auto itr = mp.begin(); itr != mp.end(); itr++){
        //     vector<int> temp = itr -> second;
        //     for(int j = 0; j < 3; j++) cout << temp[j] << ' ';
        //     cout << '\n';
        // }
        
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> temp = itr -> second;
            
            if(temp[0] > max){
                max = temp[0];
                ans = temp[2] - temp[1];       
            }
            else if(temp[0] == max){
                if(temp[2] - temp[1] < ans){
                    ans = temp[2] - temp[1];
                }   
            }
            
        }
        
        return ans;
        
       
    }
};