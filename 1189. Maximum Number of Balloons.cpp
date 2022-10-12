class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {};
        for(int i = 0; i < text.size(); i++) arr[text[i] - 'a']++;
        
        //balloon
        //b + a + ll + oo + n
        //l / 2
        arr['l' - 'a'] /= 2;
        arr['o' - 'a'] /= 2;
        
        int min = INT_MAX;
        
        string str = "balon";
        for(int c : str){
            if(arr[c - 'a'] < min) min = arr[c - 'a'];    
        }
        
        return min;
        
        
    }
};