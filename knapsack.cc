class Solution {
    //有一个背包，能盛放的物品总重量为S,设有N件物品，其重量分别为w1，w2，…，wn，
    //希望从N件物品中选择若干物品，所选物品的重量之和恰能放进该背包
    //Solution : DP
    //dp[i][j] : 前i个物品随意选择一些是否能够恰好装满容量为j的背包
    vector<int> allFitKnapsack(vector<int>& w, int S) {
        int n = w.size();
        bool dp[n+1][S+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < n+1; i++)  //初始化
            dp[i][0] = true;
        for(int i = 1; i < n; i++) {  //update
            for(int j = 1; j < S; j++) {
                if(j >= w[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-w[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        vector<int> ret;
        for(int i = n; i > 0; i--) {  //回溯求结果
            for(S >= w[i-1]) {
                if(dp[i][S]) {
                    ret.push_back(i);
                    S -= w[i-1];
                }
            }
        }
        return ret;
    }
};
