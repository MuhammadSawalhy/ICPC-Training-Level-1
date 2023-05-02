#include <bits/stdc++.h>
using namespace std;

// O(max(a, b))
int gcd_1(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b - a, a);
}

// O(log max(a, b))
int gcd_2(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}
