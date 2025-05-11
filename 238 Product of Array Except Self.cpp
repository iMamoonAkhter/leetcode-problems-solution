class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        
        int pre = 1, post = 1;
        
        // Calculate prefix products
        for (int i = 0; i < nums.size(); i++) {
            result[i] = pre;
            pre = nums[i] * pre;
        }
        
        // Calculate postfix products and multiply with prefix
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = result[i] * post;
            post = post * nums[i];
        }
        
        return result;
    }
};