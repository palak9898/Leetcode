class Solution {
public:
    long long factorial(int num, int k) {
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (num - i) / (i + 1);  // Compute (num-i)/(i+1) iteratively
    }
    return res;
}

int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = min(m - 1, n - 1);  // Choose the smaller one for efficiency
    return factorial(N, r);
}
};