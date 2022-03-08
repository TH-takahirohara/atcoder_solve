#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  
  int output = 0;
  for (int i=1; i<=N; i++) {
    if (i % 2 == 0) {
      continue;
    }
    
    int cnt = 0;
    
    for (int j=1; j<=i; j++) {
      if (i % j == 0) {
        cnt++;
      }
    }
    
    if (cnt == 8) {
      output++;
    }
  }
  
  cout << output << endl;
}

