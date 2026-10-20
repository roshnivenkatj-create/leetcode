class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end());

        vector<int> pref(n + 1, 0), suff(n + 1, 1e9);

        for (int i = 0; i < n; i++)
            pref[i + 1] = max(pref[i], nums[i]);

        for (int i = n - 1; i >= 0; i--)
            suff[i] = min(suff[i + 1], nums[i]);

        vector<int> drop(n, 0);
        for (int i = 1; i < n; i++)
            drop[i] = drop[i - 1] + (nums[i - 1] > nums[i]);

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;

            for (int s = 0; s < n; s += k) {
                int e = s + k - 1;
                int d = drop[e] - drop[s] + (nums[e] > nums[s]);

                if (d > 1 || pref[s] > suff[s]) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
