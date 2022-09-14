class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        int curr = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(curr){
                    ans++;
                }
                curr = 0;
            }
            else{
                curr = 1;
            }
        }
        
        if(curr){
            ans++;
        }
        
        return ans;
    }
};

//0ms 
class Solution {
public:
    int countSegments(string s) {
        
//         if(s == "") return 0;
        
        int ans = 0;
        int i = 0;
        while(i < s.size()){
            int flag = 0;
            
            while(i < s.size() && s[i] != ' '){
                i++;
                flag = 1;
            }
            
            while(i < s.size() && s[i] == ' '){
                i++;
            }
            
            if(flag)
            ans++;
        }
        
        
        return ans;
    }
};