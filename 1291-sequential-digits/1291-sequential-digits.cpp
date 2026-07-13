class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //Brute-force Approach
        // vector<int> ans;
        // for(int i=low; i<=high; i++) {
        //     int num = i;
        //     int prev = -1;

        //     while (num > 0) {
        //         int digit = num % 10;
        //         if(prev != -1) {
        //             if(prev - 1 != digit) break;
        //         }
        //         prev = digit;
        //         num /= 10;
        //     }
        //     if(num == 0) ans.push_back(i);
        // }
        // return ans;   



        //Optimal Approach
        vector<int> ans;
        for(int i=1; i<=9; i++) {
            int num = i;
            for(int j=i+1; j<=9; j++) {
                num = num * 10 + j;
                
                if(num >= low && num <= high) ans.push_back(num);
                if(num > high) break;
            }
        }
        sort(ans.begin() , ans.end());
        return ans;


        
    }
};