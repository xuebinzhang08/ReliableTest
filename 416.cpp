 bool canPartition_1DArray(vector<int>& nums) {
        int sum = 0;
        int length = nums.size();

        for(int i = 0; i < length; i++){
            sum += nums[i];
        }
        if(sum%2 == 1) return false;
        int halfsum = sum/2;

        vector<int> dp(halfsum+1, false);
        dp[0] = true;

        for(int curr:nums){
            for(int j = halfsum; j>=curr; j--){
                dp[j] = dp[j] || dp[j-curr];
            }
        }

        return dp[halfsum];
    }

bool canPartition_2DArray(vector<int>& nums) {
        int sum = 0;
        int length = nums.size();

        for(int i = 0; i < length; i++){
            sum += nums[i];
        }
        if(sum%2 == 1) return false;
        int halfsum = sum/2;
        bool dp[length+1][halfsum+1];
        memset(dp, 0, (length+1)*(halfsum+1)*sizeof(bool));

        dp[0][0] = true;

        for(int i=1; i<=length; i++){
            for(int j=1; j<=halfsum; j++){
                int curr = nums[i-1];
                if(curr>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];
                }
            }
        }
        return dp[length][halfsum];
    }
