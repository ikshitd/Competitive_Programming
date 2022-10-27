class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> dp (n + 1) ; 
        dp[0] = 0 ; 
        for(int i = 0 ; i < n ;i++){
            if(i - 1 >= 0){
                dp[i + 1] = max(dp[i] , dp[i - 1] + nums[i]) ; 
            }
            else{
                dp[i + 1] = dp[i] + nums[i] ; 
            }
        }
        return dp[n] ; 
    }
};
