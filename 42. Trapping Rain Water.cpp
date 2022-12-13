//HARD
//using arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        int max = height[0], mx = height[n - 1];

        vector<int> a(n, 0);
        vector<int> b(n ,0);

        for(int i = 0; i < n; i++){
            if(height[i] < max) a[i] = max - height[i];
            else if(height[i] > max) max = height[i]; 

            if(height[n - i - 1] < mx) b[n - i - 1] = mx - height[n - i - 1];
            else if(height[n - i - 1] > mx) mx = height[n - i - 1];
        } 

        for(int i = 0; i < n; i++){
            if(a[i] < b[i]) ans += a[i];
            else ans += b[i];
        }

        return ans;
    }

};

//USING STACKS
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        int x;

        for(int i = 0; i < height.size(); i++){
            while(!s.empty() && height[i] > height[s.top()]){
                x = s.top();
                s.pop();
                if(s.empty()) break;

                int dist = i - s.top() - 1;
                int wall = min(height[i], height[s.top()]) - height[x];

                ans += dist * wall;
            }

            s.push(i);
        }

        return ans;
    }
};

//USING Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        //Using Pointers
        int l = 0, r = height.size() - 1, l_max = 0, r_max = 0, ans = 0;

        while(l < r){
            if(height[l] < height[r]){
                if(height[l] > l_max) l_max = height[l++];
                else ans += l_max - height[l++];
            }
            else{
                if(height[r] > r_max) r_max = height[r--];
                else ans += r_max - height[r--];
            }
        }

        return ans;
    }
};