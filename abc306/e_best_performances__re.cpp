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
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> X(Q);
  vector<ll> Y(Q);
  rep(i,0,Q) {
    int x;
    ll y;
    cin >> x >> y;
    x--;
    X.at(i) = x;
    Y.at(i) = y;
  }

  vector<ll> A(N);
  multiset<ll> msk, msnok;
  rep(i,0,K) msk.insert(0);
  rep(i,0,N-K) msnok.insert(0);
  ll ans = 0;
  rep(i,0,Q) {
    ll mae = A.at(X.at(i));
    ll ato = Y.at(i);
    // cout << "i: " << i << " " << mae << " " << ato << " min: " << *begin(msk) << endl;
    auto it = msk.find(mae);
    if (it != msk.end()) { // 対象の数がKに入ってる場合
      if (ato < *begin(msk) && *rbegin(msnok) > ato) {
        auto saidai_nok = *rbegin(msnok);
        auto it_saidai_nok = msnok.find(saidai_nok);
        ans += saidai_nok - mae;
        msk.erase(it);
        msnok.erase(it_saidai_nok);
        msk.insert(saidai_nok);
        msnok.insert(ato);
      } else {
        ans += ato - mae;
        msk.erase(it);
        msk.insert(ato);
      }
    } else { // 対象の数が上位K個に入っていない場合
      auto it_nok = msnok.find(mae);
      if (ato > *begin(msk)) {
        auto saisho_k = *begin(msk);
        auto it_saisho_k = msk.find(saisho_k);
        ans += ato - saisho_k;
        msk.erase(it_saisho_k);
        msnok.erase(it_nok);
        msk.insert(ato);
        msnok.insert(saisho_k);
      } else {
        msnok.erase(it_nok);
        msnok.insert(ato);
      }
    }
    A.at(X.at(i)) = ato;
    cout << ans << endl;
  }
}
