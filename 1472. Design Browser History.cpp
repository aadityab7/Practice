//220 ms - two stacks and curr variable
class BrowserHistory {
    stack<string> bk, fr;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        //push curr in back
        //clear forward

        bk.push(curr);
        while(fr.size()) fr.pop();

        curr = url;
    }
    
    string back(int steps) {
        //put curr in forward
        //remove websites from back and put them in curr

        int b = min(steps, (int)bk.size());

        for(int i = 0; i < b; i++){
            fr.push(curr);
            curr = bk.top();
            bk.pop();
        }

        return curr;
    }
    
    string forward(int steps) {
        //push curr to back 
        //make curr = forward.top

        int f = min(steps, (int)fr.size());

        for(int i = 0; i < f; i++){
            bk.push(curr);
            curr = fr.top();
            fr.pop();
        }

        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


 /*
 back = leet google face
 curr = link
 forward = 
 */


//229 ms - without using curr
class BrowserHistory {
    stack<string> bk, fr;
public:
    BrowserHistory(string homepage) {
        bk.push(homepage);
    }
    
    void visit(string url) {
        bk.push(url);
        while(fr.size()) fr.pop();
    }
    
    string back(int steps) {
        while(bk.size() > 1 && steps > 0){
            fr.push(bk.top());
            bk.pop();   
            steps--;
        }

        return bk.top();
    }
    
    string forward(int steps) {
        while(fr.size() > 0 && steps > 0){
            bk.push(fr.top());
            fr.pop();
            steps--;
        }

        return bk.top();
    }
};