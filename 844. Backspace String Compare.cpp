class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(s == t) return true;
        
        vector<char> a, b;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(a.size()) a.pop_back();
            }
            else{
                a.push_back(s[i]);
            }
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(b.size()) b.pop_back();
            }
            else{
                b.push_back(t[i]);
            }
        }
        
        return a == b;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "";
        int ig = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '#'){
                ig++;
            }
            else{
                if(ig == 0) a += s[i];
                else ig--;
            }
        }
        
        cout << a << '\n';
        //utg
        //
        
        int j = 0;
        ig = 0;
        
        for(int i = t.size() - 1; i >= 0; i--){
            if(t[i] == '#'){
                ig++;
            }
            else{
                
                if(ig == 0){ 
                    
                    if(j < a.size()){
                        if(a[j] != t[i]) return false;

                        j++;
                    }
                    else return false;
                    
                }
                else{
                    ig--;
                }
                
            }
        }
        
        return j == a.size();
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(s == t) return true;
        
        string a = "";
        int ig = 0;
        int i, j = 0;
        
        for(i = s.size() - 1; i >= 0; i--){
            if(s[i] == '#') ig++;
            else{
                if(ig == 0) a += s[i];
                else ig--;
            }
        }
        
        
        ig = 0;
        
        for(i = t.size() - 1; i >= 0; i--){
            if(t[i] == '#') ig++;
            else{
                if(ig == 0){ 
                    if(j < a.size()){
                        if(a[j] != t[i]) return false;

                        j++;
                    }
                    else return false;
                    
                }
                else ig--;
            }
        }
        
        return j == a.size();
    }
};