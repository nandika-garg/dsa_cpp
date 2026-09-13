class Solution {
public:

    struct State {
        long long score;
        vector<int> ids;
    };

    State better(const State& a, const State& b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        return (a.ids < b.ids ? a : b);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store original index
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],   // l
                intervals[i][1],   // r
                intervals[i][2],   // weight
                i                   // original index
            });
        }

        // Sort by left endpoint
        sort(a.begin(), a.end());

        // next[i] = first interval j such that a[j].l > a[i].r
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {

            long long r = a[i][1];

            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        // dp[i][k] = best answer using intervals from i onward
        // with at most k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        // dp[n][k] = empty answer with score 0
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 0; k <= 4; k++) {

                // Don't take interval i
                State skip = dp[i + 1][k];

                State take = {-1, {}};

                if (k > 0) {

                    take.score =
                        a[i][2] + dp[nxt[i]][k - 1].score;

                    take.ids = dp[nxt[i]][k - 1].ids;

                    // Add original index
                    take.ids.push_back((int)a[i][3]);

                    // IMPORTANT:
                    // ids must be sorted because the final answer
                    // needs lexicographical comparison.
                    sort(take.ids.begin(), take.ids.end());
                }

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }
};