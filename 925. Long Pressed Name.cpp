class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        char prev = 'X';
        
        for(int i = 0; i < typed.size(); i++){
            if(j < name.size() && typed[i] == name[j]){
                prev = name[j];
                j++;
            }
            else if(typed[i] == prev){
                continue;
            }
            else return false;
        }
        
        return j == name.size();
    }
};