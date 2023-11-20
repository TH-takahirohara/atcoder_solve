#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i,0,M) {
    int a;
    cin >> a;
    a--;
    A.at(i) = a;
  }

  set<pair<int,int>> st;
  vector<int> cnt(N);
  rep(i,0,M) {
    int hito = A.at(i);
    int cnt_ima = cnt.at(hito);
    if (cnt_ima == 0) {
      st.insert(make_pair(-1, hito));
      cnt.at(hito)--;
    } else {
      int cnt_new = cnt_ima - 1;
      st.insert(make_pair(cnt_new, hito));
      cnt.at(hito)--;
    }
    auto sai_pair = *begin(st);
    cout << sai_pair.second + 1 << endl;
  }
}
