class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long long a = 6; // ABA
        long long b = 6; // ABC
        
        for(int i = 2; i <= n; i++) {
            long long new_a = (3*a + 2*b) % MOD;
            long long new_b = (2*a + 2*b) % MOD;
            
            a = new_a;
            b = new_b;
        }
        
        return (a + b) % MOD;
    }
};