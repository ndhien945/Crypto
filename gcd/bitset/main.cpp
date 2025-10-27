#include <iostream>
#include <bitset>
#define N 1032 // length of bits
// structure: 1 bit for sign
using namespace std;
#define ll long long
#define FORD(i,a,b) for(int i = a;i >= b;i--)
#define FOR(i,a,b) for(int i = a;i <= b;i++)
bool cmp(bitset<1032> a,bitset<1032> b) // compare with bit
{
    FORD(i,N - 1,0)
        if (a[i] != b[i])
            return a[i] > b[i];
    return false; 
}
bitset<1032> bitset_add(bitset<1032> a,bitset<1032> b) // a is always greater than b
{
    bitset<1032> c;
    bool carry = false;
    FOR(i,0, N - 1)
    {
        if (!carry)
        {
            c[i] = (a[i] ^ b[i]); 
            if (a[i] == 1 && b[i] == 1) carry = true;
        }
        else
        {
            c[i] = !(a[i] ^ b[i]);
            if (a[i] == 0 && b[i] == 0) carry = false;
        }
    }
    return c;
}
bitset<1032> bitset_2nd_complement(bitset<1032> a)
{
    bitset<1032> b;
    FOR(i,0,N - 1)
        b[i] = !a[i];
    bitset<1032> one;
    one[0] = 1;
    b = bitset_add(b,one);
    return b;
}
bitset<1032> bitset_gcd(bitset<1032> a,bitset<1032> b) {
    ll cnt = 0;
    while (a[0] == 0 && b[0] == 0)
    {
        a = a >> 1;
        b = b >> 1;
        cnt++;
    }
    while (a.any() && b.any()) // a > 0 && b > 0
    {
        while (a[0] == 0)
            a = a >> 1;
        while (b[0] == 0)
            b = b >> 1;
        if (cmp(a,b)) a = bitset_add(a,bitset_2nd_complement(b));
        else b = bitset_add(b,bitset_2nd_complement(a));
    }
    a = a << cnt;
    return a;
}
bitset<1032> a, b;

int main()
{
    a = std::bitset<1032>("10010101100"); // 1196
    b = std::bitset<1032>("10110110000"); // 1456
    cout << bitset_gcd(a,b) << endl; // 
    return 0;
}