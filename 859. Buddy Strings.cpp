class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        int count = 0;
        int f = -1, se = -1;
        
        for(int i = 0; i < s.size(); i++){
            //if we find there are 2 elements out of place 
            //then we can swap them and be done 
            if(s[i] != goal[i]){
                if(f == -1) f = i;
                else se = i;
                
                count++;
            }
        }
        
        if(count == 2){
            //store the index at which they are not equal
            if(s[f] == goal[se] && s[se] == goal[f]) return true;
            
            return false;
        }
        else if(count == 0){
            //check if there is a alphabet which occurs twice or more
            unordered_set<char> st;
            
            for(int i = 0; i < s.size(); i++){
                if(st.find(s[i]) != st.end()) return true;
                    
                st.insert(s[i]);
            }
            
        }
        
        return false;
    }
};

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s.size() < 2 || goal.size() < 2) return false;
        
        int count = 0;
        int f = -1, se = -1;
        
        for(int i = 0; i < s.size(); i++){
            //if we find there are 2 elements out of place 
            //then we can swap them and be done 
            if(s[i] != goal[i]){
                if(f == -1) f = i;
                else se = i;
                
                count++;
            }
        }
        
        if(!count){
            //check if there is a alphabet which occurs twice or more
            int arr[26] = {};
            
            for(int i = 0; i < s.size(); i++){
                if(arr[s[i] - 'a']) return true;
                    
                arr[s[i] - 'a'] = 1;
            }
        }
        else if(count == 2 && s[f] == goal[se] && s[se] == goal[f]) return true;
        
        return false;
    }
};