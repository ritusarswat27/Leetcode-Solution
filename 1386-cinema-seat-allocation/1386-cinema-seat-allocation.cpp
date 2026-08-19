class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    //Brute-force Approach
    //     int count = 0;
    //     for (int row = 1; row <= n; row++) {

    //         bool left = true;
    //         for (int s = 2; s <= 5; s++) {
    //             for (auto r : reservedSeats) {
    //                 if (r[0] == row && r[1] == s) {
    //                     left = false;
    //                     break;
    //                 }
    //             }
    //             if (left == false) break;
    //         }

    //         bool mid = true;
    //         for (int s = 4; s <= 7; s++) {
    //             for (auto r : reservedSeats) {
    //                 if (r[0] == row && r[1] == s) {
    //                     mid = false;
    //                     break;
    //                 }
    //             }
    //             if (!mid) break;
    //         }

    //         bool right = true;
    //         for (int s = 6; s <= 9; s++) {
    //             for (auto r : reservedSeats) {
    //                 if (r[0] == row && r[1] == s) {
    //                     right = false;
    //                     break;
    //                 }
    //             }
    //             if (!right) break;
    //         }

    //         if (left && right) count += 2;
    //         else if (left) count += 1;
    //         else if (right) count += 1;
    //         else if (mid) count += 1;
    //     }
    // return count;



    int count = (n * 2);
    sort(reservedSeats.begin() , reservedSeats.end());

        for (int i=0; i<reservedSeats.size(); i++) {
            int curr = reservedSeats[i][0];
            bool left = true , right = true , mid = true;

            while(i < reservedSeats.size() && reservedSeats[i][0] == curr) {
                if(reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5) {
                    left = false;
                    if(reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 5) mid = false;
                }
                else if(reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9) {
                    right = false;
                    if(reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 7)
                    mid = false;
                }
                i++;
            }

            if(!left && !mid && !right) count -= 2;
            else if(!left || !mid || !right) count--;
            i--;
        }
    return count;
    }
};