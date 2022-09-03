#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S;
  cin >> S;
  if (S=="Monday") {
    cout << 5 << endl;
  } else if (S== "Tuesday") {
    cout << 4 << endl;
  } else if (S=="Wednesday") {
    cout << 3 << endl;
  } else if (S=="Thursday") {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
  }
}
