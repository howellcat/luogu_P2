#include<bits/stdc++.h>

#define maxn 520

using namespace std;

int x[maxn], y[maxn], z[maxn];

int main() {
    string a, b;
    cin >> a >> b;
    int len = max(a.length(), b.length());//len = 长度
    for (int i = a.length() - 1, j = 1; i >= 0; i--, j++)
        x[j] = a[i] - '0';
    for (int i = b.length() - 1, j = 1; i >= 0; i--, j++)
        y[j] = b[i] - '0';
    for (int i = 1; i <= len; i++) {
        z[i] += x[i] + y[i];
        z[i + 1] = z[i] / 10;
        z[i] %= 10;
    }
    if (z[len + 1])
        len++;
    for (int i = len; i >= 1; i--)
        cout << z[i];
}