class Solution {
public:
    int minimizeXor(int num1, int num2) {
        //count bits in num2
        int bits = 0;
        
        while(num2 > 0){
            if(num2%2){ 
                bits++;
            }
            
            num2/=2;
        }
        
        //we have required number of bits 
        //now place them where bits are in num1
        //and start placing the remaining bits from the end
        
        vector<int> b;
        
        while(num1 > 0){
            if(num1 % 2){ 
                b.push_back(1);
            }
            else{
                b.push_back(0);
            } 
            
            num1 /= 2;
        }
        
        for(int i = b.size() - 1; i >= 0; i--){
            if(bits > 0){
                if(b[i] == 1){
                    bits--;
                    b[i] = -1;
                }
            }
            else{
                break;
            }
        }
        
        //if there are still bits remaining then start from end and start filling the 0's with one's 
        int i = 0;
        while(bits > 0){
            if(i < b.size()){
                if(b[i] == 0){
                    b[i] = -1;
                    bits--;
                }
                
                i++;
            }
            else{
                b.push_back(-1);
                bits--;
            }
        }
        
        
        //convert the bit representation stored in b to x
        int x = 0;
        long numb = 1;
        
        for(int i = 0; i < b.size(); i++){
            if(b[i] == -1){
                x += numb;
            }
            
            numb *= 2; 
            //cout << b[i] << ' ';
        }
        //cout << '\n';
        
        return x;
    }
};

/*
3 => 0011
5 => 101
11
//place all the bits where the other bus 
//2
*/