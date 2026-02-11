class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int cnt1=0,cnt2=0;
            for(int j=i;j<n;j++){
                if(!(mp.find(nums[j])!=mp.end())){
                    (nums[j]%2==0)?cnt1++:cnt2++;
                }
                if(cnt1==cnt2){
                    ans=max(ans,j-i+1);
                }
                mp[nums[j]]++;
                
            }
            // cout<<cnt1<<" "<<cnt2<<endl;
            mp.clear();
        }
        return ans;


    }
};