//My solution updating all elements on increment - 36 ms
class CustomStack {
vector<int> st;
int tos = -1;
int max;

public:
    CustomStack(int maxSize) {
        st.resize(maxSize);        
        max = maxSize;
    }
    
    void push(int x) {
        if(tos == max - 1) return;
        ++tos;
        st[tos] = x;
    }
    
    int pop() {
        if(tos == -1) return -1;
        return st[tos--];
    }
    
    void increment(int k, int val) {
        if(tos == -1) return;

        for(int i = 0; i < k && i <= tos; i++){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

//keep a seperate record of increments in an array and add that at pop() time - 36 ms
class CustomStack {
vector<int> arr;
stack<int> st;
int tos = -1;
int max;

public:
    CustomStack(int maxSize) {
        max = maxSize;
        arr.resize(max, 0);      
    }
    
    void push(int x) {
        if(tos == max - 1) return;

        st.push(x);
        tos++;
    }
    
    int pop() {
        if(tos == -1) return -1;
        
        int val = st.top();
        st.pop();

        int inc = arr[tos];

        if(tos > 0){
            arr[tos - 1] += arr[tos];
        } 

        arr[tos] = 0;
        tos--;

        return val + inc;
    }
    
    void increment(int k, int val) {
        if(tos == -1) return;

        int x = k - 1;
        if(tos < x) x = tos;

        arr[x] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

//just using a vector without resizing - 44 ms - imp : see how min() is used with functions inside
class CustomStack {
    vector<int> st;
    int max;
public:
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(st.size() < max) st.push_back(x);
    }
    
    int pop() {
        if(st.size() == 0) return -1;

        int res = st.back();
        st.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int x = min(k, (int)st.size());

        for(int i = 0; i < x; i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */