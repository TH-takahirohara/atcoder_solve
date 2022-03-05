#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  
  vector<ll> ruiseki_1(N+1, 0);
  vector<ll> ruiseki_2(N+1, 0);
  
  for (int i=1; i<=N; i++) {
    int c_i;
    int p_i;
    cin >> c_i >> p_i;
    if (c_i == 1) {
      ruiseki_1.at(i) += p_i;
    } else {
      ruiseki_2.at(i) += p_i;
    }
    ruiseki_1.at(i) += ruiseki_1.at(i-1);
    ruiseki_2.at(i) += ruiseki_2.at(i-1);
  }
  
  int Q;
  cin >> Q;
  
  for (int i=0; i<Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << ruiseki_1.at(R) - ruiseki_1.at(L-1) << " " << ruiseki_2.at(R) - ruiseki_2.at(L-1) << endl;
  }
}
