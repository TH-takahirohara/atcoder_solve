#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<ll> juku(N);
  for (int i=0; i<N; i++) {
    cin >> juku.at(i);
  }
  
  sort(juku.begin(), juku.end());
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int num_seito;
    cin >> num_seito;
    auto val = lower_bound(juku.begin(), juku.end(), num_seito);
    
    if (val == juku.begin()) {
      cout << abs(*val - num_seito) << endl;
    } else {
      cout << min(abs(*val - num_seito), abs(*(val--) - num_seito)) << endl;
    }
  }
}
