

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);
        
        long long low = 1, high = 2e18, ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cnt = mid / a + mid / b + mid / c 
                          - mid / ab - mid / bc - mid / ac 
                          + mid / abc;
            
            if (cnt >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};
