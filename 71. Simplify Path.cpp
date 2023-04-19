class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string curr = "", ans = "";

        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(curr == ".." && !s.empty()) s.pop();
                else if(curr != "" && curr != "." && curr != "..") s.push(curr);

                curr = "";
            }
            else curr += path[i];
        }

        if(curr == ".." && !s.empty()) s.pop();
        else if(curr != "" && curr != "." && curr != "..") s.push(curr);

        if(s.empty()) return "/";

        //we need to create a new array or stack to store in correct order
        vector<string> arr;
        while(!s.empty()) arr.push_back(s.top()), s.pop();

        for(int i = arr.size() - 1; i >= 0; i--){
            ans += '/';
            ans += arr[i];
        }

        return ans;
    }
};
