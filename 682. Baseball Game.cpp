class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> arr;
        int temp;
        
        for(int i = 0; i < op.size(); i++){
            
            if(op[i] == "+"){
                //add last two elements from arr and and add it to arr;
                temp = arr[arr.size() - 1] + arr[arr.size() - 2];
                arr.push_back(temp);
            }
            else if(op[i] == "D"){
                //get the last element from the arr and double it         
                temp = arr[arr.size() - 1];
                arr.push_back(temp * 2);
            }
            else if(op[i] == "C"){
                //remove last element 
                arr.pop_back();
            }
            else{
                 arr.push_back(stoi(op[i]));
            }
            
        }
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            ans += arr[i];
        }
        return ans;
    }
};