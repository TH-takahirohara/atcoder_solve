#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> houses(N);
  vector<ll> schools(N);
  
  for (int i=0; i<N; i++) cin >> houses.at(i);
  for (int i=0; i<N; i++) cin >> schools.at(i);
  
  sort(houses.begin(), houses.end());
  sort(schools.begin(), schools.end());
  
  ll sum = 0;
  for (int i=0; i<N; i++) {
    sum += abs(houses.at(i) - schools.at(i));
  }
  cout << sum << endl;
}
