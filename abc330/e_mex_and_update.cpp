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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  set<int> st_a, st_mex;
  map<int,int> mp_a;
  rep(i,0,N) {
    st_a.insert(A.at(i));
    mp_a[A.at(i)]++;
  }

  vector<int> T = A;

  sort(T.begin(), T.end());
  int tmp = -1;
  rep(i,0,N) {
    if (tmp < T.at(i) - 1) {
      // cout << "st_mex insert: " << tmp+1 << endl;
      st_mex.insert(tmp+1);
    }
    tmp = T.at(i);
  }
  if (tmp != 1e9) {
    // cout << "st_mex insert: " << tmp+1 << endl;
    st_mex.insert(tmp+1);
  }

  rep(iter,0,Q) {
    int idx, x;
    cin >> idx >> x;
    idx--;

    int kison_a = A.at(idx);
    A.at(idx) = x;
    mp_a[kison_a]--;
    mp_a[x]++;
    st_a.insert(x);

    if (mp_a.at(kison_a) == 0) { // その値がAから無くなった場合
      if (st_a.count(kison_a)) st_a.erase(kison_a); // st_aから削除
      st_mex.insert(kison_a); // mexになりうる
    }

    if (st_mex.count(x)) { // xがmex候補であった場合
      st_mex.erase(x);
      if (!st_a.count(x+1)) { // x+1がAにない場合
        st_mex.insert(x+1);
      }
    }

    cout << *begin(st_mex) << endl;
  }
}
