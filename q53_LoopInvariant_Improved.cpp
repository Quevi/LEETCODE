class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0], sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};