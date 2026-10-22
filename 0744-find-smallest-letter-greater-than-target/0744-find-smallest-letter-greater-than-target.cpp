class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int left = 0 , right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(letters[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return letters[left % letters.size()];
        
    }
};