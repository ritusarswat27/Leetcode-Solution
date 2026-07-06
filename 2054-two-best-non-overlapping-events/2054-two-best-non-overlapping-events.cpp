class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        //Brute-force Approach
        // sort(events.begin() , events.end());
        // int maxValue = 0
        // for(int i=0; i<n; i++) {
        //     int value = events[i][2];
        //     int endTime = events[i][1];
        //     int startTime = events[i][0];
        //     for(int j=0; j<n; j++) {
        //         if(i != j && endTime < events[j][0]) {
        //             maxValue = max(maxValue , value + events[j][2]);
        //         }
        //     }
        //     maxValue = max(maxValue , value);
        // }
        // return maxValue;    




        sort(events.begin() , events.end());

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) suffixMax[i] = max(events[i][2], suffixMax[i + 1]);

        int maxValue = 0;

        for(int i=0; i<n; i++) {
            int value = events[i][2];
            int endTime = events[i][1];
            int left = i + 1 , right = n - 1 , idx = n;
            maxValue = max(maxValue , value);

            while(left <= right) {
                int mid = (left + right) / 2;
                if(events[mid][0] > endTime) {
                    idx = mid;
                    right = mid - 1;
                }
                else left = mid + 1;
                
            }
            if (idx < n) maxValue = max(maxValue, value + suffixMax[idx]);
        }
        return maxValue;    
    }
};