#include "func.h"
ll gcd_version1_basic(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while  (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
ll gcd_version1_update(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd_version1_update(b, a % b);
}
ll gcd_version2_basic(ll a, ll b) {
    ll g = 1;
    while (a % 2 == 0 && b % 2 == 0)
    {
        a = a / 2;
        b = b / 2;
        g = g * 2;
    }
    while (a > 0 && b > 0)
    {
        while (a % 2 == 0)
            a = a / 2;
        while (b % 2 == 0)
            b = b / 2;
        auto t = abs(a - b);
        if (a > b) a = t;
        else b = t;
    }
    g = g * a;
    return g;
}
bool cmp(ll a,ll b) // compare with bit
{
    for (int i = sizeof(ll) * 8 - 1; i >= 0; i--)
        if (((a >> i) & 1) != ((b >> i) & 1))
            return ((a >> i) & 1) > ((b >> i) & 1);
    return false; // a = b
}
ll gcd_version2_update(ll a, ll b) {
    ll cnt = 0;
   while ((a & 1) == 0 && (b & 1) == 0)
    {
        a = a >> 1;
        b = b >> 1;
        cnt++;
    }
    while (a > 0 && b > 0)
    {
        while (a & 1 == 0)
            a = a >> 1;
        while (b & 1 == 0)
            b = b >> 1;
        auto t = abs(a - b);
        if (cmp(a,b)) a = t;
        else b = t;
    }
    a = a << cnt;
    return a;
}