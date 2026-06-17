class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N2 = nums.size();
        int n  = N2 / 2;
        long long total = 0;
        for (int x : nums) total += x;

        // split
        vector<int> L(nums.begin(), nums.begin() + n),
                    R(nums.begin() + n, nums.end());

        // 1) enumerate subset‐sums by pick‐count
        vector<vector<long long>> sumsL(n+1), sumsR(n+1);
        // left half
        for (int mask = 0; mask < (1<<n); mask++) {
            int cnt = __builtin_popcount(mask);
            long long s = 0;
            for (int i = 0; i < n; i++)
                if (mask & (1<<i)) s += L[i];
            sumsL[cnt].push_back(s);
        }
        // right half
        for (int mask = 0; mask < (1<<n); mask++) {
            int cnt = __builtin_popcount(mask);
            long long s = 0;
            for (int i = 0; i < n; i++)
                if (mask & (1<<i)) s += R[i];
            sumsR[cnt].push_back(s);
        }

        // 2) sort right‐side buckets for binary search
        for (int k = 0; k <= n; k++)
            sort(sumsR[k].begin(), sumsR[k].end());

        long long best = LLONG_MAX;
        double half = total / 2.0;

        // 3) combine
        for (int k = 0; k <= n; k++) {
            auto &SL = sumsL[k];
            auto &SR = sumsR[n-k];
            for (long long sL : SL) {
                // target for sR is (total/2 - sL)
                double need = half - sL;
                // binary search in SR
                auto it = lower_bound(SR.begin(), SR.end(), need);
                // check this and previous
                if (it != SR.end()) {
                    long long S = sL + *it;
                    best = min(best, llabs(2*S - total));
                }
                if (it != SR.begin()) {
                    --it;
                    long long S = sL + *it;
                    best = min(best, llabs(2*S - total));
                }
            }
        }

        return int(best);
    }
};
