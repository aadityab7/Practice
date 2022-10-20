class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        
        for(string a : words){
            for(string b : words){
                if(a == b) continue;
                if(b.find(a) != -1){
                    ans.push_back(a);
                    break;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        string  s;
        int  size, found;
        int i, j, k;
        
        for(i = 0; i < words.size(); i++){                
            //check if this word is sub of some other sub   
            s = words[i];
            size = s.size();
            found = 0;
            
            for(j = 0; j < words.size(); j++){
                
                //check only larger words
                if(words[j].size() > size){
                    
                    for(k = 0; k <= words[j].size() - size; k++){
                        
                        if(words[j][k] == s[0]){
                            string temp = words[j].substr(k, size);
                            if(temp == s){
                                ans.push_back(s);
                                found = 1;
                                break;
                            }
                        }
                        
                    }//end for each char in word
                    
                }    
                
                if(found) break;
                
            }//end of for checking in each word
        
        }//end of for each word
        
        
        return ans;
    }
};