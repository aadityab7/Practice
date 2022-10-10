class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int sum = 0;
        
        while(k){
            if(i < nums.size() && nums[i] < 0){
                nums[i] = -nums[i];
                i++;
            }
            else{
                if(k % 2) {
                    //find the smallest abs val and make it neg 
                    int min = nums[0];
                    for(int j = 0; j < nums.size(); j++){
                        if(nums[j] < min) min = nums[j];
                        if(j && nums[j] > nums[j-1]) break;
                    }
                    
                    sum -= 2 * min;
                }
                break;
            }
            
            k--;
        }
        
        
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ' ';
            sum += nums[i];
        }
        
        cout << '\n';
        return sum;
    }
};

/*
2 3 4 
100 
-1 0 2 3
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int sum = 0;
        
        while(k){
            if(i < nums.size()){
                if(nums[i] < 0){
                    nums[i] = -nums[i];
                    i++;
                }
                else{
                    //check which is smaller prev or curr;
                    if(k % 2){
                        if(i){
                            if(nums[i] < nums[i - 1]){
                                nums[i] = -nums[i];
                            }
                            else{
                                nums[i - 1] = -nums[i - 1];
                            }
                        }
                        else{
                            nums[i] = -nums[i];
                        }
                    }
                    
                    break;
                }
            }       
            else{
                if(k % 2) {
                    //find the smallest abs val and make it neg 
                    int min = 0;
                    for(int j = 0; j < nums.size(); j++){
                        if(nums[j] < nums[min]) min = j;
                        if(j && nums[j] > nums[j-1]) break;
                    }
                    
                    nums[min] = -nums[min];
                }
                break;
            }
            
            
            k--;
        }
        
        
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ' ';
            sum += nums[i];
        }
        
        cout << '\n';
        return sum;
    }
};

/*
2 3 4 
100 
-1 0 2 3
*/