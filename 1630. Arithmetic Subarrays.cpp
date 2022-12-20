class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();

        vector<bool> ans(n, true);
        vector<int> curr;

        for(int i = 0; i < n; i++){
            curr.clear();

            for(int j = l[i]; j <= r[i]; j++) curr.push_back(nums[j]);

            sort(curr.begin(), curr.end());

            int diff = curr[1] - curr[0];
            for(int j = 2; j < curr.size(); j++){
                if(curr[j] - curr[j - 1] != diff){
                    ans[i] = false;
                    break;
                }
            }

        }

        return ans;    
    }
};

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        int diff, i, j;

        vector<bool> ans(n, true);
        
        for(i = 0; i < n; i++){
            //creating a subarray from a array
            vector<int> curr(nums.begin() + l[i], nums.begin() + r[i] + 1);

            sort(curr.begin(), curr.end());

            diff = curr[1] - curr[0];
            for(j = 2; j < curr.size(); j++){
                if(curr[j] - curr[j - 1] != diff){
                    ans[i] = false;
                    break;
                }
            }

        }

        return ans;    
    }
};


//using patterns (arithmatic progression based) - 83 ms
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;

        for(int i = 0; i < n; i++){
            bool res = true;

            //size of range
            int size = r[i] - l[i] + 1;

            //create an array of the given size => elements = 0
            vector<bool> curr(size, false);

            //find the minimum and maximum elements in the range
            int min = nums[l[i]], max = nums[r[i]];
            for(int j = l[i]; j <= r[i]; j++){
                if(nums[j] < min) min = nums[j];
                if(nums[j] > max) max = nums[j]; 
            }

            //check if d > 0 and d is integer or not
            if(min == max){
                res = true;
            }
            else if((min - max) % (size - 1)){
                res = false;
            }
            else{
                //common difference 
                int d = (max - min) / (size - 1);
                //cout << d << ' ';

                int j = l[i];

                for(; j <= r[i]; j++){
                    int temp = nums[j] - min;
                    if((temp % d) || (curr[temp / d])) break;
                    curr[temp / d] = true;
                }

                if(j <= r[i]) res = false;
            }
            
            ans.push_back(res);
        }

        return ans;
    }
};

//using minmax_element() function
//using patterns (arithmatic progression based)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n, true);
        int i, j, size;

        for(i = 0; i < n; i++){
            bool res = true;

            //size of range
            size = r[i] - l[i] + 1;

            //create an array of the given size => elements = 0
            vector<bool> curr(size, false);

            //find the minimum and maximum elements in the range
            auto [min, max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);

            //check if d > 0 and d is integer or not
            if(*min == *max){
                continue;
            }
            else if((*min - *max) % (size - 1)){
                ans[i] = false;
            }
            else{
                //common difference 
                int d = (*max - *min) / (size - 1);

                for(j = l[i]; j <= r[i]; j++){
                    if(((nums[j] - *min) % d) || (curr[(nums[j] - *min) / d])) break;
                    curr[(nums[j] - *min) / d] = true;
                }

                if(j <= r[i]) ans[i] = false;
            }
        }

        return ans;
    }
};