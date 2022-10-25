class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        string x;
        
        for(int i = 0; i < logs.size(); i++){
            x = logs[i];
            //if "./" remain in the same folder do nothing
            if(x != "./"){
                if(x == "../"){
                    if(count) count--;
                }
                else count++;
            }
        }
        
        return count;
    }
};