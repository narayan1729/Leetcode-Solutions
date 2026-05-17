class Solution {
public:
    void dfs(int i, vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    int  fun(int n){
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        vector<int>b=nums;
        sort(b.begin(), b.end(), [&](int i, int j) {
            int s1 = fun(i);
            int s2 = fun(j);
            if (s1 != s2)
                return s1 < s2;
            return i < j;
        });
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[b[i]]=i;
        }
        for(int i=0;i<n;i++){
            int u=i;
            int v=mp[nums[i]];
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }

        return n-ans;
    }

};