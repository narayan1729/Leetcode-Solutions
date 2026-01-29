class Solution {
public:
using ll=long long;
    long long minimumCost(string source, string target, vector<char>& a, vector<char>& b, vector<int>& cost) {
        
        vector<vector<ll>>dist(26,vector<ll>(26,1e9));
        int n=a.size();
        for(int i=0;i<n;i++){
            int u=a[i]-'a';
            int v=b[i]-'a';
            ll w=cost[i];
            dist[u][v]=min(w,dist[u][v]);
        }
        for(int i=0;i<26;i++) dist[i][i]=0;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        // for(auto it:dist){
        //     for(auto t:it) cout<<t<<" ";
        // }
        ll ans=0;n=source.size();
        for(int i=0;i<n;i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            // if(u==v) continue;
            if(dist[u][v]>=1e9){
                return -1;
            }
            ans+=dist[u][v];
        }
        return ans;

    }
};