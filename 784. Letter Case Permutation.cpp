class Solution {

    void helper(int index, vector<int> & pos, vector<string> & ans, string & curr){
        //change the case of letter at index 
        string temp = curr;
        if(temp[pos[index]] >= 'a' && temp[pos[index]] <= 'z') temp[pos[index]] -= ('a' - 'A');
        else temp[pos[index]] -= ('A' - 'a');
        
        ans.push_back(temp);

        //with the new string move to next indices
        for(int i = index + 1; i < pos.size(); i++)
            helper(i, pos, ans, temp);
    }

public:
    vector<string> letterCasePermutation(string s) {
        //array of alphabet positions
        vector<int> pos;
        for(int i = 0; i < s.size(); i++)
            if(s[i] < '0' || s[i] > '9') pos.push_back(i);
            
        vector<string> ans;
        string curr = s;

        ans.push_back(curr);

        for(int i = 0; i < pos.size(); i++)
            helper(i, pos, ans, curr);

        return ans;
    }
};

//A little more elegant solution
class Solution {
    void helper(int index, string & curr, vector<string> & ans){
        if(index == curr.size()) ans.push_back(curr);
        else{
            //moving forward with changing the alphabet at index
            if(curr[index] < '0' || curr[index] > '9'){
                string temp = curr;
                if(temp[index] >= 'a' && temp[index] <= 'z') temp[index] -= ('a' - 'A');
                else temp[index] -= ('A' - 'a');

                helper(index + 1, temp, ans); 
            }

            //moving forward without changing alphabet / when a digit
            helper(index + 1, curr, ans);
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(0, s, ans);
        return ans;
    }
};