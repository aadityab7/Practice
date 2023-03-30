class Solution {
    bool isScrambleHelper(unordered_map<string, bool> &memo, string s1, string s2) {
        int i, len = s1.size();
        bool result = false;

        // Base cases
        if (len == 0) {
            return true;
        } else if (len == 1) {
            return s1 == s2;
        } else {
            // Check if we have already computed the result for this pair of strings
            if (memo.count(s1 + s2)) {
                return memo[s1 + s2];
            }

            // Check if the two strings are equal
            if (s1 == s2) {
                result = true;
            } else {
                // Check all possible split positions
                for (i = 1; i < len && !result; ++i) {
                    // Check if s1[0..i-1] and s2[0..i-1] are valid scrambles of each other
                    // and if s1[i..len-1] and s2[i..len-1] are valid scrambles of each other
                    result = result || (isScrambleHelper(memo, s1.substr(0, i), s2.substr(0, i)) && isScrambleHelper(memo, s1.substr(i, len - i), s2.substr(i, len - i)));

                    // Check if s1[0..i-1] and s2[len-i..len-1] are valid scrambles of each other
                    // and if s1[i..len-1] and s2[0..len-i-1] are valid scrambles of each other
                    result = result || (isScrambleHelper(memo, s1.substr(0, i), s2.substr(len - i, i)) && isScrambleHelper(memo, s1.substr(i, len - i), s2.substr(0, len - i)));
                }
            }

            // Save the intermediate result in the memoization table
            return memo[s1 + s2] = result;
        }
    }
public:

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return isScrambleHelper(memo, s1, s2);
    }
};