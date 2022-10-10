class Solution {
public:
    string removeDuplicates(string s) {
        //use a fucking stack like data structure dumbass
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        //use a fucking stack like data structure dumbass
        vector<char> arr(s.size() + 1);
        int j = -1;
        
        for(int i = 0; i < s.size(); i++){
            j++;
            arr[j] = s[i];
            // arr.push_back(s[i]);
            
            if(j && arr[j] == arr[j - 1]){
                j -= 2;
            }    
        }
        
        string ans = "";
        for(int i = 0; i <= j; i++){
            ans += arr[i];
        }
        
        return ans;
    }
};