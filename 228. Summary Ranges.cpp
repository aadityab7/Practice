class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //we need a array of strings;
        vector<string> ans;
        
        string s;
        int counting = 0;
        int prev = 0;
        int start = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(counting){
                if(nums[i] == nums[i - 1] + 1){
                    if(prev == start){
                        s += '-';
                        s += '>';
                    }
                    prev = nums[i];
                }
                else{
                    if(prev != start){
                        s += to_string(prev);
                    }
                    
                    ans.push_back(s);
                    
                    counting = 0;
                }
            }
            
            if(!counting){
                s = to_string(nums[i]);
                start = nums[i];
                prev = nums[i];
                counting = 1;
            }
        }
        
        //last element 
        //if we are counting 
        
        if(counting){
            if(prev != start){
                s += to_string(prev);
            }

            ans.push_back(s);
        }
        
        return ans;
    }
};