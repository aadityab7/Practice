class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        //start from the last
        vector<int> ans;
        
        int c = 0, d, n, x;
        int i = num.size() - 1;
        
        while(k > 0 || i >= 0 || c > 0){
            d = 0;
            n = 0;
            
            if(k){
                d = k % 10;
                k /= 10;
            }
            
            if(i >= 0){
                n = num[i];
                i--;
            }
            
            x = d + n + c;
            
            ans.push_back(x % 10);
            c = x / 10;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        //start from the last
        vector<int> ans;
        
        int c = k;
        int i = num.size() - 1;
        
        while(i >= 0 || c > 0){
            if(i >= 0){
                c += num[i];
                i--;
            }
            
            ans.push_back(c % 10);
            c /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};