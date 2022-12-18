//using stacks
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> ans(temperatures.size(), 0);
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && s.top().first < temperatures[i]){
                int x = s.top().second;
                ans[x] = (i - x);
                s.pop();
            }

            s.push({temperatures[i], i});
        }

        return ans;
    }
};

//stack of index
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); 
        stack<int> s;

        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};


//traversing in reverse
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0); 
        
        int max = 0, curr, i, j;

        for(i = n - 1; i >= 0; i--){
            curr = temp[i];

            if(curr >= max) max = curr;
            else{
                j = 1;
                while(curr >= temp[i + j]) j += ans[i + j]; 
                ans[i] = j;
            }
        }

        return ans;
    }
};