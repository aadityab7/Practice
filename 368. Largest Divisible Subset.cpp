class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> mp;

        for(int i : nums) mp[i].push_back(i);

        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0){
                    //for each element select the biggest subset 
                    if(mp[nums[j]].size() < mp[nums[i]].size() + 1){
                        mp[nums[j]] = mp[nums[i]];
                        mp[nums[j]].push_back(nums[j]);
                    }
                }
            }
        }

        vector<int> ans = mp.begin() -> second;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second.size() > ans.size()) ans = itr -> second;
        }

        return ans;

    }
};


/*
1 2 3 4 7 8 12

1 1 1 1 1 1 1

1 2 2 3 2 4 4
*/

//creating the subset only at last - instead of storing it with every element
//better for memory and time complexity - 67 ms
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> mp;

        //corresponding to each element store the size of subset and which subset it belongs to 

        for(int i : nums) mp[i] = {i, 1};

        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0){
                    //for each element select the biggest subset 
                    if(mp[nums[j]][1] < mp[nums[i]][1] + 1){
                        mp[nums[j]][0] = nums[i];
                        mp[nums[j]][1] = mp[nums[i]][1] + 1;
                    }
                }
            }
        }

        int mx = 0;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            mx = max(mx, itr -> second[1]);
        }

        //select any element with max elements and create the subset 

        vector<int> ans;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second[1] == mx){
                //we found our element now create a subset
                int x = itr -> first;
                ans.push_back(x);

                while(mp[x][0] != x){
                    x = mp[x][0];
                    ans.push_back(x);
                }

                break;
            }
        }

        return ans;

    }
};