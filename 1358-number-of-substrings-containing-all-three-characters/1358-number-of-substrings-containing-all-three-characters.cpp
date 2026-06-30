class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        //Brute-force Approach
        // int cnt = 0; 
        // for(int i=0; i<n; i++) {
        //     int cnta = 0 , cntb = 0 , cntc = 0;
        //     for(int j=i; j<n; j++) {
        //         if(s[j] == 'a') cnta++;
        //         else if(s[j] == 'b') cntb++;
        //         else cntc++;
        //         if(cnta > 0 && cntb > 0 && cntc > 0) cnt++;
        //     }
        // }
        // return cnt;


        //Optimal Approach
        int cnta = 0 , cntb = 0 , cntc = 0 , cnt = 0 , j = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') cnta++;
            else if(s[i] == 'b') cntb++;
            else cntc++;

            while(cnta > 0 && cntb > 0 && cntc > 0) {
                if(s[j] == 'a') cnta--;
                else if(s[j] == 'b') cntb--;
                else cntc--;
                j++;
            }   
            cnt += j; 
        }  
        return cnt; 
    }
};