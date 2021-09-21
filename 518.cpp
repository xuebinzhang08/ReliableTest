int change(int amount, vector<int>& coins) {
        int ans = 0;
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int coin :coins){
            for(int j=coin; j<=amount; j++){
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
