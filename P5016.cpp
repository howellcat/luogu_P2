#include <bits/stdc++.h>

using namespace std;

long long n, m, p1, s1, s2, l, r, MIN = LONG_LONG_MAX, MIN_index;

int main() {
    scanf("%lld", &n);
    vector<int> p(n);
    for (long long i = 0; i < n; i++)
        scanf("%d", &p[i]);
    scanf("%lld%lld%lld%lld", &m, &p1, &s1, &s2);
    p[p1 - 1] += s1;
    for (long long i = 0; i < n; i++) {
        if (i < m - 1)
            l = l + (p[i] * (m - i - 1));
        else if (i == m - 1)
            continue;
        if (i > m - 1)
            r = r + (p[i] * (i - m + 1));
    }
    for (long long i = 0; i < n; i++) {
        if (i < m - 1) {
            if (l > r)
                continue;
            if (MIN > abs((l + (m - i - 1) * s2) - r))
                MIN = abs((l + (m - i - 1) * s2) - r), MIN_index = i;
        }
        if (i == m - 1) {
            if (MIN > abs(l - r))
                MIN = abs(l - r), MIN_index = i;
        } else if (i > m - 1) {
            if (r > l)
                continue;
            if (MIN > abs((r + (i - m + 1) * s2) - l))
                MIN = abs((r + (i - m + 1) * s2) - l), MIN_index = i;
        }
    }
    printf("%lld", MIN_index + 1);
}