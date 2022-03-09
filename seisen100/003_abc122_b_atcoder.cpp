#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  
  int s_size = S.size();
  int output = 0;
  int cnt = 0;
  for (int i=0; i<s_size; i++) {
    if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
      cnt++;
    } else {
      output = max(output, cnt);
      cnt = 0;
    }
  }
  
  output = max(output, cnt);
  
  cout << output << endl;
}
