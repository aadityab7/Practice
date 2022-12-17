class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for(int i = 0; i < tokens.size(); i++){
            string str = tokens[i];

            if(str == "+" || str == "*" || str == "/" || str == "-"){
                //operator
                //put out two numbers from stack 
                long b = stol(s.top());
                s.pop();
                long a = stol(s.top());
                s.pop();

                long res;

                if(str == "+") res = a + b;
                else if(str == "-") res = a - b;
                else if(str == "*") res = a * b;
                else res = a / b;

                s.push(to_string(res)); 
            } 
            else{
                s.push(str);
            }
        }

        return stol(s.top());
    }
};