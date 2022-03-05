#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<ll> kouka(3);
  for (int i=0; i<3; i++) cin >> kouka.at(i);
  sort(kouka.begin(), kouka.end());
  ll A, B, C;
  // Aから大きい順
  A = kouka.at(2); B = kouka.at(1); C = kouka.at(0);
  
  ll minv = 1000000010;
  for (int i=0; i<10000; i++) {
    for (int j=0; j<10000; j++) {
      ll nokori = N - A*i - B*j;
      ll shou = nokori / C;
      if (nokori % C == 0 && shou >= 0 && shou <= 9999) {
        minv = min(minv, i+j+shou);
      }
    }
  }
  
  cout << minv << endl;
}
