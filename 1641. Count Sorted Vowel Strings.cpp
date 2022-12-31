//My solution - 74 ms
class Solution {
    int ans = 0;

    void helper(int start, int size){
        if(size == 0){ 
            ans++;
            return;
        }

        for(int i = start; i < 5; i++){
            helper(i, size - 1);
        }
    }

public:
    int countVowelStrings(int n) {
        helper(0, n);
        return ans;
    }
};

//0 ms
class Solution {
public:
    int countVowelStrings(int n) {
        long ans = (n + 4) * (n + 3) * (n + 2) * (n + 1);
        ans /= 24;

        return ans;
    }
};