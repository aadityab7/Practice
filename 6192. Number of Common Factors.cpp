class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        
        int min = a;
        int max = b;
        
        if(b < a){
            min = b;
            max = a;
        }
        
        for(int i = 1; i * i <= min; i++){
            if(min % i == 0){
                if(max % i == 0){
                    ans++; 
                }
                
                int x = min / i;

                if(i != x){
                    if(max % x == 0){
                        ans++;
                    }
                }

                //cout << i << ' ' << x << '\n';
                
                
            }
        }
        
        return ans;
        
    }
};