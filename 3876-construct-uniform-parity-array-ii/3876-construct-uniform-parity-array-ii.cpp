class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;

        int mini = INT_MAX;
        for(int i=0; i<n; i++) mini = min(mini , nums1[i]);

        int minOdd = INT_MAX; 
        for (int i = 0; i < n; i++) { 
            if (nums1[i] % 2 != 0) minOdd = min(minOdd, nums1[i]); 
        }  

        if (mini % 2 == 0 && minOdd != INT_MAX && minOdd > mini) return false;

        return true;
    }
};