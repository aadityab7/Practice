class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        char curr = ' ';
        int count = 0;

        vector<char> res;
        
        for(char c : chars){
            if(c != curr){
                //if more than one of prev char then append count 
                if(count > 1){
                    string cou = to_string(count);
                    for(char ch : cou)
                        res.push_back(ch);
                } 

                //append this c to resulting array
                res.push_back(c);
                curr = c;
                count = 1;
            }
            else{
                count++;
            }
        }

        if(count > 1){
            string cou = to_string(count);
            for(char ch : cou)
                res.push_back(ch);
        }

        chars = res;
        return res.size();
    }
};