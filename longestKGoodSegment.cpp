#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000;
int cnt[MAX_VAL + 1];

int main() {

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, distinct = 0;
    int max_len = 0, best_l = 0, best_r = 0;

    for (int r = 0; r < n; r++) {
        if (cnt[a[r]] == 0) {
            distinct++;
        }
        cnt[a[r]]++;

        while (distinct > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                distinct--;
            }
            l++;
        }

        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            best_l = l;
            best_r = r;
        }
    }

    cout << best_l + 1 << " " << best_r + 1 << "\n";
    return 0;
}