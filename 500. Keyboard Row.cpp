//0ms
class Solution {
public:
    unordered_map<char, int> mp = {
            {'q' , 0},
            {'w' , 0},
            {'e' , 0}, 
            {'r' , 0},
            {'t' , 0},
            {'y' , 0},
            {'u' , 0},
            {'i' , 0},
            {'o' , 0},
            {'p' , 0},
            {'a' , 1},
            {'s' , 1},
            {'d' , 1},
            {'f' , 1},
            {'g' , 1},
            {'h' , 1},
            {'j' , 1},
            {'k' , 1},
            {'l' , 1},
            {'z' , 2},
            {'x' , 2},
            {'c' , 2},
            {'v' , 2},
            {'b' , 2},
            {'n' , 2},
            {'m' , 2}
        };
    
    vector<string> findWords(vector<string>& words) {
         
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++){
            //for each word in array
            int count[3] = {};
            
            for(int j = 0; j < words[i].size(); j++){
                //check which row the character belong to 
                if(words[i][j] >= 'a' && words[i][j] <= 'z'){
                    count[mp[words[i][j]]] = 1;
                }
            }
            
            int rows = 0;
            for(int j = 0; j < 3; j++){
                if(count[j]){
                    rows++;
                }
            }
            
            if(rows == 1){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};


///4ms
class Solution {
public:
    unordered_map<char, int> mp = {
            {'q' , 0},
            {'w' , 0},
            {'e' , 0}, 
            {'r' , 0},
            {'t' , 0},
            {'y' , 0},
            {'u' , 0},
            {'i' , 0},
            {'o' , 0},
            {'p' , 0},
            {'a' , 1},
            {'s' , 1},
            {'d' , 1},
            {'f' , 1},
            {'g' , 1},
            {'h' , 1},
            {'j' , 1},
            {'k' , 1},
            {'l' , 1},
            {'z' , 2},
            {'x' , 2},
            {'c' , 2},
            {'v' , 2},
            {'b' , 2},
            {'n' , 2},
            {'m' , 2}
        };
    
    vector<string> findWords(vector<string>& words) {
         
        vector<string> ans;
        char c;
        int flag;
        int curr;
        
        for(int i = 0; i < words.size(); i++){
            flag = 1;
            
            for(int j = 0; j < words[i].size(); j++){
                c = words[i][j];
                
                if(c >= 'A' && c <= 'Z'){
                    c = c - 'A' + 'a';
                }
                
                if(j){
                    if(mp[c] != curr){
                        flag = 0;
                        break;
                    }
                }
                else{
                    curr = mp[c];
                }
            }
            
            if(flag){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};