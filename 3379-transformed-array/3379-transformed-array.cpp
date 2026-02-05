class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[i]=nums[(i%n+nums[i]%n)%n];
            }
            else ans[i]=nums[(i%n+n+nums[i]%n)%n];
        }
        return ans;
    }
};