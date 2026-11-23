// задание 1
// #include <bits/stdc++.h>
// using namespace std;

// struct R { long long s, p, q, b; }; // sum, prefix, suffix, best

// R f(vector<int>& a, int l, int r) {
//     if (l == r) { long long x = a[l]; return {x, x, x, x}; }
//     int m = (l + r) / 2;
//     R L = f(a, l, m), Rr = f(a, m + 1, r);
//     return {
//         L.s + Rr.s,
//         max(L.p, L.s + Rr.p),
//         max(Rr.q, Rr.s + L.q),
//         max({L.b, Rr.b, L.q + Rr.p})
//     };
// }

// int main() {
//     int n; cin >> n;
//     vector<int> a(n);
//     for (int& x : a) cin >> x;
//     cout << f(a, 0, n - 1).b;
// }


// задание 2
// #include <bits/stdc++.h>
// #include <filesystem>
// using namespace std;
// namespace fs = filesystem;

// int main() {
//     string dir, outPath;
//     getline(cin, dir);
//     getline(cin, outPath);

//     ofstream out(outPath);
//     vector<fs::path> v;

//     for (auto& e : fs::directory_iterator(dir))
//         if (e.path().extension() == ".txt" && fs::absolute(e.path()) != fs::absolute(outPath))
//             v.push_back(e.path());

//     sort(v.begin(), v.end());

//     for (auto& p : v) {
//         ifstream in(p);
//         out << in.rdbuf() << '\n';
//     }
// }


// задание 3
// #include <bits/stdc++.h>
// using namespace std;

// void bin(unsigned long long n) {
//     if (n > 1) bin(n / 2);
//     cout << n % 2;
// }

// int main() {
//     long long n; cin >> n;
//     if (n < 0) {
//         cout << '-';
//         bin(0ULL - (unsigned long long)n);
//     } else bin(n);
// }