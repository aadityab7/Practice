class Solution {
public:
    string toGoatLatin(string s) {
        int size = s.size(), start, count;
        string ans = "", last = "";
        
        int i = 0;
        while(i < size){
            //find word
            
            start = i;
            count = 0;
            
            while(i < size && s[i] != ' '){
                i++;
                count++;
            }
            
            i++;
        
            string word = s.substr(start, count);
            
            if(word[0] != 'a' && word[0] != 'e' && word[0] != 'i' && word[0] != 'o' && word[0] != 'u'&& word[0] != 'A' && word[0] != 'E' && word[0] != 'I' && word[0] != 'O' && word[0] != 'U'){
                word = word.substr(1, word.size() - 1);
                word += s[start];
            }
            
            last += 'a';
            
            ans += (word + "ma" + last);
            
            if(i < size) ans += ' ';
        }
        
        return ans;
        
    }
};

//using string stream class of C++
class Solution {
public:
    string toGoatLatin(string s) {
        unordered_set<char> st {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        stringstream str(s), ans;
        string last = "a", word;
        
        while(str >> word){
            if(st.find(word[0]) != st.end()){
                //starting with vowel;
                ans << ' ' << word << "ma" << last;
            }
            else{
                //starting with consonent;
                ans << ' ' << word.substr(1) << word[0] << "ma" << last; 
            }
            
            //cout << word << '\n';
            last += 'a';
        }
        
        return ans.str().substr(1);
        // return word;
    }
};