long long maxRunTime(int n, vector<int>& batteries) {
         long long left = 0, right = 0;
        for (long long b : batteries) right += b;  // max total energy

        right /= n;  // upper bound for T

        auto canRun = [&](long long T) {
            long long total = 0;
            for (long long b : batteries)
                total += min(b, T);
            return total >= T * n;
        };

        long long ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (canRun(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
        
    }