class Solution {
public:
    using ll=long long;
    using pii = pair<ll, ll>;
    pii fun(pii& p, vector<int>& a) {
        ll i = p.first;
        ll j = p.second;
        ll ans = -1e9;
        ll val = 0;
        for (ll k = i+1; k <= j; k++) {
            val += a[k];
            ans = max(ans, val);
        }
        ll ans1 = -1e18;
        val = 0;
        for (ll k = j-1; k >= i; k--) {
            val += a[k];
            ans1 = max(ans1, val);
        }
        return {ans, ans1};
    }

    long long maxSumTrionic(vector<int>& nums) {
        ll n = nums.size();
        map<pii, pii> mp;
        vector<pair<ll, ll>> a;

        ll left = 0;

        for (ll right = 1; right < n; right++) {

            if (nums[right] <= nums[right - 1]) {
                if (right - left > 1)
                    a.push_back({left, right - 1});

                left = right;
            }
        }

        if (n - left > 1)
            a.push_back({left, n - 1});

        for (auto it : a) {
            mp[it] = fun(it, nums);
        }
        ll m = a.size();
        ll ans = -1e18;
        for (ll i = 1; i < m; i++) {
            ll val = 0;
            ll r = a[i].first ;
            ll l = a[i - 1].second ;
            bool flag=false;
            for(ll j=l+1;j<=r;j++){
                if(nums[j]==nums[j-1]){
                    flag=true;break;
                }
                
            }
            if(flag) continue;

            for (ll j = l; j <= r; j++) {
                val += nums[j];
            }
            ans = max(ans, val + mp[a[i]].first + mp[a[i - 1]].second);
        }
        return ans;
    }
};