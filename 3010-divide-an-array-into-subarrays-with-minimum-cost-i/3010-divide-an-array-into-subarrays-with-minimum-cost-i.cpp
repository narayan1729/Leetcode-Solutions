class Solution {
public:
    int minimumCost(vector<int>& a) {
        int ans=0,n=a.size();
        int mn1=1e9,mn2=1e9;
        for(int i=1;i<n;i++){
            if(a[i]<mn1){
                mn2=mn1;
                mn1=a[i];
            }else if(a[i]>=mn1&& a[i]<mn2){
                mn2=a[i];
            }
        }
        ans=mn1+mn2+a[0];
        return ans;
    }
};