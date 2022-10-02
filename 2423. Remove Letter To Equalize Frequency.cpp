class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp;
        for(int i = 0 ; i < word.size(); i++){
            mp[word[i]]++;
        }
        
        //go to each word and the try decreasing it and check rest if they are equal
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            (itr -> second)--;
            
            int flag = 1;
            int flag2 = 1;
            int freq = 0;
            
            for(auto i = mp.begin(); i != mp.end(); i++){
                
                if(i -> second == 0) continue;
                
                if(flag){
                    flag = 0;
                    freq = i -> second;
                    continue;
                }
                
                if(freq != i -> second){
                    flag2 = 0;
                    break;
                }
                
            }
            
            if(flag2) return true;
            
            (itr -> second)++;
        }
        
        return false;
    }
};