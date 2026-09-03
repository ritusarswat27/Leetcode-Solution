class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;

        int mini = INT_MAX;
        int minIndex = -1;
        for(int i=0; i<n; i++) {
            if(nums1[i] < mini) {
                mini = min(mini , nums1[i]);
                minIndex = i;
            }
        }

        int minOdd = INT_MAX; 
        for (int i = 0; i < n; i++) { 
            if (nums1[i] % 2 != 0) minOdd = min(minOdd, nums1[i]); 
        }  
        
        if (mini % 2 == 0 && minOdd != INT_MAX && minOdd > mini) return false;

        // bool even = false , odd = false;
        // if(mini % 2 == 0) even = true;
        // else odd = true;

        // for(int i=0; i<n; i++) {
        //     if(nums1[i] == mini) {
        //         nums2[i] = mini;
        //     }
        //     else if(even == true) {
        //         if(nums1[i] % 2 == 0) nums2[i] = nums1[i];
        //         else if(nums1[i] - nums1[j] >=1 && (nums1[i] - nums1[j]) % 2 == 0) nums2[i] = nums1[i] - nums1[j];
        //         else return false;
        //     }
        //     else if(odd == true) {
        //         if(nums1[i] % 2 != 0) nums2[i] = nums1[i];
        //         else if(nums1[i] - nums1[j] >=1 && (nums1[i] - nums1[j]) % 2 != 0) nums2[i] = nums1[i] - nums1[j];
        //         else return false;
        //     }
        // }
        return true;
    }
};