class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ltr(n), rtl(n), ans(n);
        
        int prev = -1, p = -1;
        
        for(int i = 0; i < n; i++){
            //LTR
            if(s[i] == c){ 
                ltr[i] = 0;
                prev = i;
            }
            else{
                if(prev != -1) ltr[i] = i - prev;
                else ltr[i] = INT_MAX;
            }    
            
            //RTL
            if(s[n - i - 1] == c){
                rtl[n - i - 1] = 0;
                p = (n - i - 1);
            }    
            else{
                if(p != -1) rtl[n - i - 1] = (p - (n - i - 1));
                else rtl[n - i - 1] = INT_MAX;
            }
        
        }
        
        
        for(int i = 0; i < n; i++){
            ans[i] = min(ltr[i], rtl[i]);
        }
        
        return ans;
        
    }
};


//less memory more time
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);
        vector<int> arr;
        
        for(int i = 0; i < n; i++){
            if(s[i] == c) arr.push_back(i);
        }
        
        //we have a sorted array of values of pos of c in s
        for(int i = 0; i < n; i++){
            //find the min dist 
            //this gives the next pos of c 
            int x = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            
            if(x == arr.size()) ans[i] = i - arr[x - 1];
            else if(x == 0) ans[i] = arr[x] - i;
            else ans[i] = min(i - arr[x - 1], arr[x] - i);
        }
        
        return ans;
        
    }
};