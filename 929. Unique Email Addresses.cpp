class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        int f, ignore;
        string mail;
        
        for(string email : emails){
            
            mail = "";
            f = 0;
            ignore = 0;
            
            for(char c : email){
                //remove dots before @ 
                if(c == '@') f = 1;
                
                if(f) mail += c;
                else if(!ignore){
                    
                    if(c == '+'){
                        //ignore everything in name
                        ignore = 1;
                    }
                    else if(c == '.'){
                        continue;
                    }
                    else{
                        mail += c;
                    }
                }
            }
            
            st.insert(mail);
        }
        
        return st.size();
    }
};