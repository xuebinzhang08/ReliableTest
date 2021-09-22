string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int maxl = 1;
        string ans = "";
        ans += s[0];
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int i = n-1; i>=0; i--){
            // dp[i][i] = 1;
            for(int j = i+1; j< n; j++){
                if(s[i] == s[j]){
                    if(j==i+1 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(j-i+1 > maxl){
                            maxl = j-i+1;
                            ans = s.substr(i, j-i+1);
                        }
                    }

                }
            }
        }
        return ans;
    }
