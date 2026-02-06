class Solution {
public:
    using ll=long long ;
    int minRemoval(vector<int>& a, int k) {
        int n=a.size();
        sort(a.rbegin(),a.rend());
        vector<ll>b(n);
        ll ans=0;
        for(int i=0;i<n;i++){
            b[i]=a[i]*(k*1LL);
        }
        int i=0;
        for(int j=0;j<n;j++){

            while(i<n && a[i]>b[j]){
                i++;
            }
            if(i==n)break;
            ans=max(ans,(j-i+1)*1LL);
        }
        return n-ans;
        
    }
};