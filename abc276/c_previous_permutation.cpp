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
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i,0,N) cin >> vec.at(i);

  vector<int> test = vec;
  sort(test.begin(), test.end());

  vector<int> ansvec = test;
  rep(i,0,N-1) {
    vector<int> tmpvec;
    rep(k,0,i) tmpvec.push_back(vec.at(k));

    int tar = vec.at(i);
    vector<int> nv;
    int mx = -1;
    rep(j,i+1,N) {
      nv.push_back(vec.at(j));
      if (vec.at(j) < tar && vec.at(j) > mx) mx = vec.at(j);
    }

    if (mx == -1) continue;
    rep(j,0,nv.size()) {
      if (nv.at(j) == mx) nv.at(j) = tar;
    }
    sort(nv.begin(), nv.end());
    reverse(nv.begin(), nv.end());

    tmpvec.push_back(mx);
    rep(j,0,nv.size()) {
      tmpvec.push_back(nv.at(j));
    }

    if (tmpvec > ansvec) {
      ansvec = tmpvec;
    }
  }

  rep(i,0,N) {
    cout << ansvec.at(i) << " ";
  }
  cout << endl;
}
