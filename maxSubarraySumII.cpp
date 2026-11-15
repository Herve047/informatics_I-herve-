#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {


    int n;
    long long a, b;
    if (!(cin >> n >> a >> b)) return 0;

    vector<long long> x(n + 1);
    vector<long long> S(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        S[i] = S[i - 1] + x[i];
    }

    multiset<long long> window;
    long long max_sum = -4e18; 

    for (int r = 1; r <= n; ++r) {
        
        if (r - a >= 0) {
            window.insert(S[r - a]);
        }

        if (r - b - 1 >= 0) {
            auto it = window.find(S[r - b - 1]);
            if (it != windows.end()) {
                window.erase(it);
            }
        }
        if (!window.empty()) {
            max_sum = max(max_sum, S[r] - *window.begin());
        }
    }

    cout << max_sum << "\n";

    return 0;
}