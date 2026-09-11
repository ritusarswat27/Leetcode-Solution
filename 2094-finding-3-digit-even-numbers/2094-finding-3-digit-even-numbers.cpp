class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int , int> mpp;
        for(auto num : digits) mpp[num] += 1;
        unordered_map<int , int> temp(mpp.begin() , mpp.end());

        vector<int> ans;
        
        for(int i=100; i<1000; i+=2) {
            int val = i;
            bool flag = false;
            while(val != 0) {
                int rem = val % 10;
                if(mpp.count(rem)) {
                    mpp[rem] -= 1;
                    if(mpp[rem] == 0) mpp.erase(rem);
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
                val /= 10;
            }
            mpp = temp;
            if(flag == true) ans.push_back(i);
        }
        return ans;
    }
};