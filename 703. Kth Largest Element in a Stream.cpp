class KthLargest {
private:
    map<int, int> mp;
    int pos; 
public:
    KthLargest(int k, vector<int>& nums){
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        pos = k;
    }
    
    int add(int val){
        //each time we add an element
        mp[val]++;
        
        int temp = pos;
        
        for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
            if(itr -> second >= temp) return itr-> first;
            
            temp -= itr -> second;
        }
        
        return mp.begin() -> second;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//USING MIN-HEAP
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        pq = priority_queue<int, vector<int>, greater<int>> (nums.begin(), nums.end());
        for(int i = k; i < nums.size(); ++i) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};


class KthLargest {
    priority_queue<int,vector<int>,greater<>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++) {
            if(pq.size()<k)
                pq.push(nums[i]);
            else {
                if(nums[i]>pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k)
           pq.push(val);
        else {
            if(val>pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};