//This problem is solved using the concept of Dynamic programming 
//breaking down the problem into smaller parts and then 
//using the result of smaller part 
//to solve the next step
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        if(n){
            for(int i = 0; i < n; i++){
                for(string left : generateParenthesis(i)){
                    for(string right : generateParenthesis(n - i - 1)){
                        ans.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        else{
            ans.push_back("");
        }
        
        return ans;
    }
};



//Something called Backtracking
class Solution {
private:
    vector<string> ans;
    void create(int open, int close, int size, string curr){
        if(curr.size() == size * 2) {   
            ans.push_back(curr);
            return;
        }
        
        if(open < size) create(open + 1, close, size, curr + '(');
        
        if(close < open) create(open, close + 1, size, curr + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        create(0, 0, n, "");
        return ans;
    }
};