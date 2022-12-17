//naive brute force approach - O(n^2) - 466ms
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);

        for(int i = 0; i < boxes.size(); i++){
            //for each box calculate the dist to all other boxes
            for(int j = 0; j < boxes.size(); j++){
                if(i != j && boxes[j] == '1'){
                    ans[i] += abs(i - j);
                }
            }
        }

        return ans;
    }
};


//using arrays ltr and rtl - 11 ms
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        vector<int> ltr(n, 0);
        vector<int> rtl(n, 0);

        int cl = 0, currl = 0, currr = 0, rl = 0;
        
        for(int i = 0; i < n; i++){
            ltr[i] = currl + cl;
            currl = currl + cl;

            if(boxes[i] == '1') cl++;

            rtl[n - i - 1] = currr + rl;
            currr = currr + rl;

            if(boxes[n - i - 1] == '1') rl++;
        }

        for(int i = 0; i < n; i++){
            ans[i] = ltr[i] + rtl[i];
        }


        return ans;
    }
};

//Condensed version - using a single array - 7ms
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), cl = 0, currl = 0, currr = 0, rl = 0;

        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++){
            //ltr
            currl += cl;
            ans[i] += currl;
            
            if(boxes[i] == '1') cl++;

            //rtl
            currr += rl;
            ans[n - i - 1] += currr;
            
            if(boxes[n - i - 1] == '1') rl++;
        }

        return ans;
    }
};