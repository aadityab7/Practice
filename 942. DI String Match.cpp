class Solution {
public:
    vector<int> diStringMatch(string s) {
        int pos = 1, neg = -1, min = 0;
        
        vector<int> ans;
        ans.push_back(0);
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I'){
                //jump to next pos number
                ans.push_back(pos);
                pos++;
            }
            else{
                //jump to next neg number
                min = neg;
                ans.push_back(neg);
                neg--;
            }
        }
        
        //find the min in ans;
        //add abs(min) to all the numbers in ans
        min = abs(min);
        
        if(min){
            
            for(int i = 0; i < ans.size(); i++){
                ans[i] += min;
            }
            
        }
        
        
        return ans;
    }
};

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int pos = 1, neg = -1, min = 0;
        
        int n = s.size();
        
        vector<int> ans(n + 1);
        ans[0] = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'I') ans[i+1] = pos++;
            else{
                //jump to next neg number
                min = neg;
                ans[i + 1] = neg--;
            }
        }
        
        //find the min in ans;
        //add abs(min) to all the numbers in ans
        min = abs(min);
        
        if(min){
            
            for(int i = 0; i <= n; i++){
                ans[i] += min;
            }
            
        }
        
        
        return ans;
    }
};

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int lo = 0, hi = n;
        
        vector<int> ans(n + 1);
        
        for(int i = 0; i < n; i++)
            if(s[i] == 'I') ans[i] = lo++;
            else ans[i] = hi--;
        
        ans[n] = lo;
        
        return ans;
    }
};