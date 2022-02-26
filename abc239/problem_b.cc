#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X;
  cin >> X;
  
  int64_t output;
  output = X / 10;
  if (X < 0 && (X % 10 != 0)) {
    output -= 1;
  }
  
  cout << output;
}
