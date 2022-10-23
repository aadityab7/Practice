class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> gr(arr.size());
        int max = -1;
        
        for(int i = arr.size() - 1; i >= 0; i--){
            gr[i] = max;
            if(arr[i] > max) max = arr[i];
        }
        
        return gr;
    }
};