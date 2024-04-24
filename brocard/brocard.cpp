#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

#define elif else if
#define pb push_back
#define pop pop_back

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

ll factorial(int n) {
    ll fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
        if (fact > INF)
            return -1;
    }
    return fact;
}

bool isPerfectSquare(ll x) {
    ll s = sqrt(x);
    return s * s == x;
}

int main() {
    const int MAX_N = 10000;
    vector<tuple<int, int, int>> solutions;
    for (int n = 1; n <= MAX_N; ++n) {
        ll fact = factorial(n);
        if (fact == -1) {
            cout << "Factorial of " << n << " is too large to handle.\n";
            continue;
        }
        for (int a = 1; a <= 10000; ++a) {
            ll factPlusOne = fact + a;
            int b = sqrt(a);
            if (isPerfectSquare(factPlusOne)) {
                ll m = sqrt(factPlusOne);
                if (m > b && n > b) {
                    solutions.push_back(make_tuple(a, n, m));
                }
            }
        }
    }
    sort(solutions.begin(), solutions.end());
    for (const auto& solution : solutions) {
        cout << "Found solution: a = " << get<0>(solution) << ", n = " << get<1>(solution) << ", m = " << get<2>(solution) << endl;
    }
    return 0;
}

// int main() {
//     const int MAX_N = 10000;
//     cout << "Searching for solutions to Brocard's problem (n! + 1 = m^2) for n up to " << MAX_N << "...\n";
//     for (int n = 1; n <= MAX_N; ++n) {
//         ll fact = factorial(n);
//         if (fact == -1) {
//             cout << "Factorial of " << n << " is too large to handle.\n";
//             continue;
//         }
//         ll factPlusOne = fact + 1;
//         if (isPerfectSquare(factPlusOne)) {
//             ll m = sqrt(factPlusOne);
//             if (m > 1) {
//                 cout << "Found solution: n = " << n << ", m = " << m << endl;
//             }
//         }
//     }
//     return 0;
// }