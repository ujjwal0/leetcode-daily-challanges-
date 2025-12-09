 int n = nums.size();
        map<long long,long long> mp;
        int ans = 0;
        int mod = 1e9 + 7;

        for (int i = 1; i < n; i++) {
            mp[nums[i] + 1e7]++;
        }

        mp[nums[0] - 1e7]++;

        for(int i = 1; i < n - 1; i++)
        {
            mp[nums[i] + 1e7]--;
            long long val = (mp[nums[i]*2 - 1e7] * mp[nums[i]*2 + 1e7]) % mod;
            ans += val;
            ans %= mod;
            mp[nums[i] - 1e7]++;
        }

        return ans;