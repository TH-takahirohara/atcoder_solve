#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> B(N);
  
  for (int i=0; i<N; i++) cin >> A.at(i);
  for (int i=0; i<N; i++) cin >> B.at(i);
  
  ll diff = 0LL;
  for (int i=0; i<N; i++) {
    diff += abs(A.at(i) - B.at(i));
  }
  
  
  if (K < diff) {
    cout << "No" << endl;
    return 0;
  } else if (K % 2 == diff % 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
