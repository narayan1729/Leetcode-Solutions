class Solution {
public:
    int mod=1e9+7;
    vector<int>pse(vector<int>a,int n){
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>a[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>a,int n){
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>a=pse(arr,n);
        vector<int>b=nse(arr,n);
        int ans=0;
        for(int i=0;i<n;i++){
            int val=arr[i];
            int fre=((i-a[i])*(b[i]-i))%mod;
            ans=(ans+(((long long)fre*arr[i])%mod))%mod;
            
        }
        return ans;
    }
};