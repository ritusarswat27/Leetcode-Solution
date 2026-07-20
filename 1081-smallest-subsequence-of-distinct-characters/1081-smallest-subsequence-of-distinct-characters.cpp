class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<bool> visited(26 , false);
        stack<char> st;

        vector<int> lastIndex(26 , 0);
        for(int i=0; i<n; i++) lastIndex[s[i] - 'a'] = i;

        for(int i=0; i<n; i++) {
            if(visited[s[i] - 'a'] == true) continue;

            if(st.empty()) {
                st.push(s[i]);
                visited[s[i] - 'a'] = true;
            }
            else {
                while(!st.empty() && s[i] < st.top() ) {
                    int id = lastIndex[st.top() - 'a'];
                    if(id > i) {
                        visited[st.top() - 'a'] = false;
                        st.pop();
                    }
                    else break;
                }
                
                st.push(s[i]);
                visited[s[i] - 'a'] = true;
            }
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};