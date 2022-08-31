// sort関数に新しいアルファベット順に対応するようなソート条件を渡せばよい。
//(参考: http://blog.cafeform.com/?p=1453)
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

string X; 
map<char,int> mp;

bool comp(string &lh, string &rh) {
  int len = min(lh.size(), rh.size());
  rep(i,0,len) {
    if (mp.at(lh.at(i)) < mp.at(rh.at(i))) {
      return true;
    } else if (mp.at(lh.at(i)) > mp.at(rh.at(i))) {
      return false;
    }
  }
  return lh.size() < rh.size();
}

int main() {
  cin >> X;
  rep(i,0,26) {
    mp[X.at(i)] = i;
  }
  int N; cin >> N;
  vector<string> S(N);
  rep(i,0,N) cin >> S.at(i);

  sort(S.begin(), S.end(), comp);
  rep(i,0,N) {
    cout << S.at(i) << endl;
  }
}
