#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll N, P, Q;

void mul(ll &a, ll b) {
  a *= b;
  a %= P;
}

int main() {
  cin >> N >> P >> Q;
  vector<ll> A(N);
  
  rep(i, N) {
    cin >> A.at(i);
  }
  
  ll sum = 0LL;
  for (int i=0; i<N-4; i++) {
    for (int j=i+1; j<N-3; j++) {
      for (int k=j+1; k<N-2; k++) {
        for (int l=k+1; l<N-1; l++) {
          for (int m=l+1; m<N; m++) {
            ll seki = 1;
            mul(seki, A.at(i));
            mul(seki, A.at(j));
            mul(seki, A.at(k));
            mul(seki, A.at(l));
            mul(seki, A.at(m));
            if (seki % P == Q) {
              sum += 1;
            }
          }
        }
      }
    }
  }
  
  cout << sum << endl;
}

