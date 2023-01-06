// 8 ms
class Solution {
public:
    int trailingZeroes(int n) {
        //count the number of 2's 5's and 10's
        int fives = 0, twos = 0, num;

        for(int i = 1; i <= n; i++){
            int num = i;
            while(num && num % 5 == 0){
                fives++;
                num /= 5;
            }

            while(num && num % 2 == 0){
                twos++;
                num /= 2;
            }
        }

        return min(fives, twos);
    }
};

//3 ms
//using the powers of 5 to calculate the multiples of 5 in range (there will always be enough 2's)
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(long long i = 5; n / i > 0; i *= 5) ans += n / i;
        return ans;
    }
};