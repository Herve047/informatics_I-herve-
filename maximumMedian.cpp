#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    
    int n;
    long long k;
    cin >> n >> k;
 
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    sort(a.begin(), a.end());
 
    int m = n / 2;
    long long low = a[m], high = a[m] + k, ans = a[m];
 
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long ops = 0;
 
        for (int i = m; i < n; i++) {
            if (a[i] < mid) ops += (mid - a[i]);
            if (ops > k) break;
        }
 
        if (ops <= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
 
    cout << ans << endl;
    return 0;
}