class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        
        for(int i = 0; i < nums.size(); i++) {
            if(res.empty() || nums[i] > res.back()) res.push_back(nums[i]);
            else{
                *lower_bound(res.begin(), res.end(), nums[i]) = nums[i];
            }
        }
        
        return res.size();
    }
};