class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;

        for(string &op : operations)
            if(op[1] == '+') count += 1;
            else count -= 1;   
        
        return count;
    }
};