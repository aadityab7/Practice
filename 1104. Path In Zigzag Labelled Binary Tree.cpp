class Solution {
    vector<int> arr;
public:
    vector<int> pathInZigZagTree(int label) {
        
        for(int i = 0; i <= 22; i++){
            arr.push_back(1 << i);
        }

        //find at which level does label belong to
        int level = 1;

        for(int i = 0; i < 22; i++){
            if(arr[i] > label){
                level = i;
                break;
            }
        }

        int flipped = 0;

        vector<int> ans(level, 0);
        level--;

        ans[level] = label;

        flipped = 1;

        label /= 2;

        while(label){
            // cout << label << '\n';
            level--;

            if(flipped){
                ans[level] = arr[level] + (arr[level + 1] - 1 - label);
                flipped = 0;
            }
            else{
                ans[level] = label;
                flipped = 1;
            }
            
            label /= 2;
        }

        return ans;
    }
};

/*
levels start from 1
max label number in each level = (2 ** level) - 1

14

level = 14 7 3 1 (4th level)

10 ^ 6 => 10 ^ 3 => 500 => 250 => 125 => 62 => 31 => 15 => 7 => 3 => 1 

11 levels max

*/