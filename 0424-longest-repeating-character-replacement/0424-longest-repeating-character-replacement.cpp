class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int n=s.size();
        vector<int>fre(26,0);
        int maxFrequency=0;
        int i=0;
        for(int j=0;j<n;j++){
            fre[s[j]-'A']++;
            maxFrequency=max(maxFrequency,fre[s[j]-'A']);
            int length=j-i+1;
            while((j-i+1)-maxFrequency>k){
                 fre[s[i]-'A'] --;
                i++;
               
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};