#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

bool is_zoro(int n) {
  if (n < 10) return true;
  if (n == 11 || n == 22 || n == 33 || n == 44 || n == 55 || n == 66 || n == 77 || n == 88 || n == 99) return true;
  return false;
}

int zoro_num(int n) {
  if (n < 10) return n;
  if (n == 11) return 1;
  if (n == 22) return 2;
  if (n == 33) return 3;
  if (n == 44) return 4;
  if (n == 55) return 5;
  if (n == 66) return 6;
  if (n == 77) return 7;
  if (n == 88) return 8;
  if (n == 99) return 9;
  return -1;
}

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  rep(i,0,N) cin >> D.at(i);

  int ans = 0;
  rep(i,0,N) {
    int tuki = i+1;
    rep(j,0,D.at(i)) {
      int hi = j+1;
      if (is_zoro(tuki) && is_zoro(hi)) {
        if (zoro_num(tuki) == zoro_num(hi)) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
