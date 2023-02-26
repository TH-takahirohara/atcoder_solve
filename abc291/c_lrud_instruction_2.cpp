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
  string S;
  cin >> S;

  map<pair<int,int>, int> mp;

  pair<int,int> p = make_pair(0,0);
  mp[p] = 1;

  rep(i,0,N) {
    if (S.at(i) == 'R') {
      p = make_pair(p.first + 1, p.second);
    } else if (S.at(i) == 'L') {
      p = make_pair(p.first - 1, p.second);
    } else if (S.at(i) == 'U') {
      p = make_pair(p.first, p.second + 1);
    } else {
      p = make_pair(p.first, p.second - 1);
    }

    if (!mp.count(p)) {
      mp[p] = 1;
    } else {
      if (mp[p] == 1) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
