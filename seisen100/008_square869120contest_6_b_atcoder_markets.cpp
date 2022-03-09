#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  
  vector<ll> A(N);
  vector<ll> B(N);
  
  for (int i=0; i<N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  
  ll sum = 9223372036854775800LL;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      ll v_in = A.at(i);
      ll v_out = B.at(j);
      
      ll tmp_sum = 0LL;
      for (int k=0; k<N; k++) {
        tmp_sum += abs(A.at(k) - v_in) + abs(A.at(k) - B.at(k)) + abs(B.at(k) - v_out);
      }
      
      sum = min(sum, tmp_sum);
    }
  }
  
  cout << sum << endl;
}

