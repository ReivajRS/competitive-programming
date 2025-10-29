#include <bits/stdc++.h>
using namespace std;

int n1, n2;
vector<int> list1, list2;
map<int, int> number_count;

void read_input() {
  while (cin >> n1 >> n2) {
    list1.push_back(n1);
    list2.push_back(n2);
    number_count[n2]++;
  }
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());
}

int part1() {  
  int ans = 0;
  for (int i = 0; i < (int)list1.size(); i++) {
    ans += abs(list1[i] - list2[i]);
  }
  return ans;
}

long long part2() {
  long long ans = 0;
  for (int i = 0; i < (int)list1.size(); i++) {
    ans += list1[i] * number_count[list1[i]];
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}