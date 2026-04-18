class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0;
        int v=n;
        while(n){
            rev=rev*10 + n%10;
            n/=10;
        }
        cout<<rev<<endl;
        return abs(rev-v);
    }
};