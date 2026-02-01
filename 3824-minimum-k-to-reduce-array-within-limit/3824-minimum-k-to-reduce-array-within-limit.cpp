class Solution {
public:
    using ll=long long ;
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        ll i=1,j=1e5;
        ll k=1e5;
        while(i<=j){
            ll mid=i+(j-i)/2;
            ll ops=0;
            for(int i=0;i<n;i++){
                ops+=(nums[i]/mid)+(nums[i]%mid!=0);
            }
            if(ops<=(mid*mid)){
                k=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
            cout<<mid<<" "<<i<<" "<<j<<" "<<ops<<endl;
        }
        return k;
    }
};