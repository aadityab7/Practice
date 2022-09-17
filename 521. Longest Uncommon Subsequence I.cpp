class Solution {
public:
    int findLUSlength(string a, string b) {
        //if the strings aren't already diff then we can just delete the first non equal element from second
        int ans = max(a.size(), b.size());
        
        if(a == b){
//             int flag = 1;
//             //delete c from a 
//             //find a element that is not equal to c in b and delete it and then they will be diff 
//             for(int i = 0; i < b.size(); i++){
//                 if(b[i] != a[0]){
//                     //done 
//                     ans--;
//                     flag = 0;
//                     break;
//                 }
//             }
            
//             if(flag){
//                 ans = -1;
//             }
            
            ans = -1;
        }
       
        return ans;
    }
};

/*
weffwaf
aeffwaf

weffwaf

abcdef
fxyz


*/