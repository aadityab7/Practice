class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        int n = pattern.size();
        vector<int> arr(n + 1);
        int i = 0, j = 0, curr;

        for(char c : pattern){
            if(c == 'I'){
                //start from curr
                curr = i + 1;
                while(j <= i){
                    arr[j] = curr--;
                    j++;
                }
            }

            i++;
        }

        curr = i + 1;
        while(j <= i){
            arr[j] = curr--;
            j++;
        }

        for(int a : arr) ans += to_string(a);
        return ans;
    }
};


/*

*/