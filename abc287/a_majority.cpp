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
  int cnt = 0;
  rep(i,0,N) {
    string s;
    cin >> s;
    if (s == "For") cnt++;
  }
  if (cnt > N/2) cout << "Yes" << endl;
  else cout << "No" << endl;
}
