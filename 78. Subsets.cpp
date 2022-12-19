class Solution {
vector<vector<int>> ans;
vector<int> curr;

void helper(const vector<int> &arr, int index){
    ans.push_back(curr);

    for(int i = index; i < arr.size(); i++){
        curr.push_back(arr[i]);
        helper(arr, i + 1);
        curr.pop_back();
    }
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};

//Using Bit Map
class Solution {

string to_bin_string(int num, int size){
    //cout << num << ' ';

    string res = "";

    while(num){
        if(num % 2 == 0) res += '0';
        else res += '1'; 

        num /= 2;
    }

    for(int j = res.size(); j < size; j++) res += '0';

    //cout << res << ' ';
    return res;
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        string x;
        vector<vector<int>> ans;
        vector<int> curr;

        for(int i = 0; i < pow(2, n); i++){
            //convert i to string of length n
            x = to_bin_string(i, n);

            curr.clear();

            for(int j = 0; j < n; j++)
                if(x[j] == '1') curr.push_back(nums[j]);
            
            ans.push_back(curr);
        }

        return ans;
    }
};