#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<ull> vec(N+1);
  vec.at(1) = 1;

  for (ull a=2; a < N; a++) {
    ull ans = 1;
    ull tmp = a;
    for (ull i=2; i*i <= a; i++) {
      if (a % i != 0) continue;
      ull kosuu = 0;
      while (tmp % i == 0) {
        kosuu++;
        tmp /= i;
      }
      ans *= (kosuu + 1);
    }
    if (tmp > 1) ans *= 2;
    if (ans != 1) vec.at(a) = ans;
  }

  // rep(i,0,N) {
  //   cout << vec.at(i) << " ";
  // }
  // cout << endl;
  ull answer = 0;
  for (ull i=1; i < N; i++) {
    answer += vec.at(i) * vec.at(N-i);
  }
  cout << answer << endl;
}
