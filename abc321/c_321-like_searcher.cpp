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
// ll ans = -1;
vector<int> ansvec;
bool owari = false;

void rec(int keta, vector<int> vec) {
  if (vec.size() == keta) {
    cnt++;
    // rep(ite,0,vec.size()) {
    //   cout << vec.at(ite);
    // }
    // cout << endl;
    if (cnt == K) {
      ansvec = vec;
      owari = true;
      return;
    }
  }
  // int last = vec.back();
  // for (int ite=last; ite <= 9; ite++) {

  // }
  // if (vec.size() == 1) {
  //   int last = vec.back();
  //   for (int ite=last; ite <= 9; ite++) {
  //     rec(keta, ite);
  //   }
  // } else {
    
  // }

  // rep(i,0,9) {
  //   if (vec.size() < keta) {
  //     rep(j,0,9) {
  //       if (vec.back() <= j) break;
  //       vector<int> nvec = vec;
  //       nvec.push_back(j);
  //       rec(keta, nvec);
  //     }
  //   }
  // }
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
  // int K;
  cin >> K;
  // if (K <= 9) {
  //   cout << K << endl;
  //   return 0;
  // }
  // cnt += 9;

  rep(i,1,11) {
    ll now = 0;
    // if (i==1) now = 1;
    // else if (i==2) now = 10;
    // else if (i==3) now = 210;
    // else if (i==4) now = 3210;
    // else if (i==5) now = 43210;
    // else if (i==6) now = 543210;
    // else if (i==7) now = 6543210;
    // else if (i==8) now = 76543210;
    // else if (i==9) now = 876543210;
    // else if (i==10) now = 9876543210;
    vector<int> st = {i-1};
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
