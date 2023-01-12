class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp = s;
        int curr = 0, size = part.size();

        for(int i = 0; i < s.size(); i++){
            temp[curr] = s[i];
            curr++;

            if(curr >= size && temp.substr(curr - size, size) == part){
                curr -= size; 
            } 
        }

        return temp.substr(0, curr);
    }
};