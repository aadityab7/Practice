class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set <int> st {2,3,5,7,11,13,17,19};
        int bits, num, ans = 0;
        
        for(int i = left; i <= right; i++){
            //for each number in the range
            //find the number of set bits in it
            bits = 0;
            num = i;
            while(num){
                if(num&1) bits++;
                num /= 2;
            }
            
            if(st.find(bits) != st.end()) ans++;
        }
        
        return ans;
    }
};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set <int> st {2,3,5,7,11,13,17,19};
        int bits, num, ans = 0;
        
        for(int i = left; i <= right; i++){
            //for each number in the range
            //find the number of set bits in it
            bits = 0;
            num = i;
            while(num){
                //imp
                num = num & (num - 1);
                bits++;
            }
            
            if(st.find(bits) != st.end()) ans++;
        }
        
        return ans;
    }
};

//10001 10000 => 10000 1111 => 00000

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        //unordered_set <int> st {2,3,5,7,11,13,17,19};
        int bits, num, ans = 0;
        
        for(int i = left; i <= right; i++){
            //for each number in the range
            //find the number of set bits in it
            bits = 0;
            num = i;
            while(num){
                //imp
                num = num & (num - 1);
                bits++;
            }
            
            if(bits == 2 || bits == 3 || bits == 5 || bits == 7 || bits == 11 || bits == 13 || bits == 17 || bits == 19) ans++;
        }
        
        return ans;
    }
};

//10001 10000 => 10000 1111 => 00000