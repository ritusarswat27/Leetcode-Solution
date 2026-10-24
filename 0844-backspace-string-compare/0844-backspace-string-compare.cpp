class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // string temp1 = "" , temp2 = "";
        // int i = m-1 , j = n-1;
        // while(i >= 0 && j >= 0) {
        //     if(s[i] == '#') i -= 2;
        //     else if(t[i] == '#') j -= 2;
        //     else {
        //         temp1 += s[i];
        //         temp2 += t[i];
        //         i-- , j--;
        //     }
        // }
        // return (temp1 == temp2);



        stack<char> st;
        string temp1 = "" , temp2 = "";

        for(int i=0; i<m; i++) {
            if(s[i] == '#') {
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }

        while(!st.empty()) {
            temp1 += st.top();
            st.pop();
        }

        for(int i=0; i<n; i++) {
            if(t[i] == '#') {
                if(!st.empty()) st.pop();
            }
            else st.push(t[i]);
        }

        while(!st.empty()) {
            temp2 += st.top();
            st.pop();
        }

        return (temp1 == temp2);

    }
};