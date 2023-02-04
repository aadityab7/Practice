class Solution {
    
    bool comp(int a[], int b[]){
        for(int i = 0; i < 26; i++) if(a[i] != b[i]) return false;
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {}, arr2[26] = {}, n = s1.size() - 1, m = s2.size();

        for(char c : s1) arr1[c - 'a']++;

        for(int i = 0; i < m; i++){
            arr2[s2[i] - 'a']++;
            
            if(i >= n){
                //we have to check 
                //if previous n chars have same number of chars as s1 or NOT
                if(comp(arr1, arr2)) return true;

                //remove i - n character which won't be needed in next iteration
                arr2[s2[i - n] - 'a']--;
            }
        } 

        return false;
    }
};