#include "countTime.h"
void count_ver0(ll a, ll b)
{
    auto start = chrono::high_resolution_clock::now();
    __gcd(a,b); // gcd_version0, lib in <algorithm>
    auto end = chrono::high_resolution_clock::now();
    cout << __gcd(a,b) << '\n';
    auto t1 = end - start;
    cout << "gcd using __gcd: " << t1.count() << " ns" << endl;
}
void count_ver1_basic(ll a, ll b)
{
    auto start = chrono::high_resolution_clock::now();
    gcd_version1_basic(a,b);
    auto end = chrono::high_resolution_clock::now();
    cout << gcd_version1_basic(a,b) << '\n';
    auto t3 = end - start;
    cout << "gcd using gcd_version1_basic: " << t3.count() << " ns" << endl;
}
void count_ver1_update(ll a, ll b)
{
    auto start = chrono::high_resolution_clock::now();
    gcd_version1_update(a,b);
    auto end = chrono::high_resolution_clock::now();
    cout << gcd_version1_update(a,b) << '\n';
    auto t2 = end - start;
    cout << "gcd using gcd_version1_update: " << t2.count() << " ns" << endl;
}
void count_ver2_basic(ll a, ll b)
{
    auto start = chrono::high_resolution_clock::now();
    gcd_version2_basic(a,b);
    auto end = chrono::high_resolution_clock::now();
    cout << gcd_version2_basic(a,b) << '\n';
    auto t4 = end - start;
    cout << "gcd using gcd_version2_basic: " << t4.count() << " ns" << endl;
}
void count_ver2_update(ll a, ll b)
{
    auto start = chrono::high_resolution_clock::now();
    gcd_version2_update(a,b);
    auto end = chrono::high_resolution_clock::now();
    cout << gcd_version2_update(a,b) << '\n';
    auto t5 = end - start;
    cout << "gcd using gcd_version2_update: " << t5.count() << " ns" << endl;
}