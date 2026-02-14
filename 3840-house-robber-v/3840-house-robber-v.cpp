class Solution {
public:
    using ll=long long ;
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<ll>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                dp[i]=nums[i];
                if(i-2>=0){
                    dp[i]+=dp[i-2];
                }
                
            }
            else{
                dp[i]=nums[i]+dp[i-1];
            }
            dp[i]=max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};