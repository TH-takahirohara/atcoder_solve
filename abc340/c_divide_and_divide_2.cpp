// メモ化再帰のオーソドックスな実装
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

map<ull,ull> memo;

ull rec(ull n) {
  if (n == 1) return 0;
  if (memo.count(n)) return memo.at(n);
  return memo[n] = n + rec(n / 2) + rec((n+1) / 2);
}

int main() {
  ull N;
  cin >> N;
  
  cout << rec(N) << endl;
}
