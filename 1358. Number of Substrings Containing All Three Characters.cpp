class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}, ans = 0, i;
        
        for(i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
            ans += 1 + min(last[0], min(last[1], last[2]));
        }

        return ans;
    }
};

/*
use 3 pointers to keep track of last occurence of a b and c

Keep on updating l1, l2 and l3.

And take the minimum of l1, l2 and l3.

Now from this min-index (min(l1, l2, l3) to the curr index i this is the smallest possible sub-string ending at curr-index i which follows the constraint.

If the smallest sub-string is from min-index to curr-index, then for every sub-string starting from index 0, 1, 2, 3, ......min-index and ending at curr-index is valid, (So how many are these...... So there are min-index + 1 sub-strings)

Add this min-index + 1 to the count.

0 3
1 4
2 5

0 1 2
0 1 2 + 1
0 1 2 + 2
0 1 2 + 3
0 1 5
0 4 2
0 4 5
3 1 2
3 4 5
3 4 2
3 1 5

3 4 5

0
0
1

2
3
4

2
2
2

*/