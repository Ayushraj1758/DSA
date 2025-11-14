class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);

        // pack jobs as {endTime, startTime, profit}
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        // sort by end time
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2];  // profit of first job

        for (int i = 1; i < n; i++) {
            int currProfit = jobs[i][2];

            // binary search for last job that ends before jobs[i] starts
            int l = 0, r = i - 1, last = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {  
                    last = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (last != -1) currProfit += dp[last];

            dp[i] = max(dp[i - 1], currProfit);
        }

        return dp[n - 1];
    }
};
