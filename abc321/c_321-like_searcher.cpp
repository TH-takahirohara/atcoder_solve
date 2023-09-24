#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int cnt = 0;
int K;
vector<int> ansvec;
bool owari = false;

void rec(int keta, vector<int> vec) {
  if (vec.size() == keta) {
    cnt++;
    if (cnt == K) {
      ansvec = vec;
      owari = true;
      return;
    }
  }
  
  if (vec.size() < keta) {
    rep(j,0,9) {
      if (vec.back() <= j) break;
      vector<int> nvec = vec;
      nvec.push_back(j);
      rec(keta, nvec);
    }
  }
}

int main() {
  cin >> K;

  rep(i,1,11) {
    rep(j,max(1,i-1),10) {
      rec(i, {j});
      if (owari) {
        rep(k,0,ansvec.size()) {
          cout << ansvec.at(k);
        }
        cout << endl;
        return 0;
      }
    }
  }
}
