#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N,K;
  ll P;
  cin>>N>>K>>P;
  int na = N/2;
  int nb = N-N/2;
  
  // 半分全列挙
  vector<ll> A(N/2), B(N-N/2);
  rep(i,0,na) cin >> A.at(i);
  rep(i,0,nb) cin >> B.at(i);
  
  // 前半(A)の全列挙
  vector<pair<ll,int>> asum;
  for (int i=0; i < (1<<na); i++) {
    ll tmp = 0;
    ll cnt1 = 0;
    for (int j=0; j < na; j++) {
      if (i & (1<<j)) {
        tmp += A.at(j);
        cnt1++;
      }
    }
    asum.push_back(make_pair(tmp,cnt1));
  }
    
  // 後半(B)の全列挙 bit全探索して、1に対応する箇所の商品を追加すると考える。
  // 選択した商品数の番目のbsumの要素に値段の総和を格納していく。
  // 例えば、bsumの3要素目には、商品を3つ選択した場合の値段を入れていく。
  vector<vector<ll>> bsum(nb+1);
  for (int i=0; i < (1<<nb); i++) {
    ll tmp = 0;
    ll cnt1 = 0;
    for (int j=0; j < nb; j++) {
      if (i & (1<<j)) {
        tmp += B.at(j);
        cnt1++;
      }
    }
    bsum.at(cnt1).push_back(tmp);
  }
  
  rep(i,0,nb+1) {
    if (bsum.at(i).empty()) continue;
    sort(bsum.at(i).begin(), bsum.at(i).end());
  }
  
  ll ans = 0;
  int siz = (int)asum.size();
  rep(i,0,siz) {
    pair<ll,int> p = asum.at(i);
    int kosuu = K - p.second;
    ll val = P - p.first;
    
    if (kosuu < 0 || val < 0 || kosuu >= nb+1) continue;
    if (bsum.at(kosuu).empty()) continue;
    ll cnt = upper_bound(bsum.at(kosuu).begin(), bsum.at(kosuu).end(), val) - bsum.at(kosuu).begin();
    ans += cnt;
  }
  cout << ans << endl;
}

