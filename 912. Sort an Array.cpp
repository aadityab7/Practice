class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size(), curr_size = 1;
        vector<int> temp = nums;

        //merge the arrays of size = 2, 4, 8, 16...
        while(curr_size <= size){
            int ptr = 0;

            //iterate over different array pairs
            for(int i = 0; i < size; i += 2 * curr_size){

                //merge array from i to i + curr_size                
                //and from i + curr_size to min(i + curr_size + curr_size, size)
                
                int x = i, y = min(i + curr_size, size);
                int x_limit = y, y_limit = min(y + curr_size, size);

                while(x < x_limit && y < y_limit){
                    if(nums[x] < nums[y]) temp[ptr++] = nums[x++];
                    else temp[ptr++] = nums[y++];
                }

                while(x < x_limit) temp[ptr++] = nums[x++];

                while(y < y_limit) temp[ptr++] = nums[y++];
            }

            //nums store the curr array 
            nums = temp;
            curr_size *= 2;
        }

        return nums;
    }
};

//Merge sort
//16 => 16 * 4
//pairs of 2 
//pairs of 4
//pairs of 8
//complete 16