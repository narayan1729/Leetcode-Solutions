class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        return *min_element(nums.begin(),nums.end());
    }
};