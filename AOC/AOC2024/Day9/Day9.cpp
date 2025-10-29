#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
string input;

void read_input() {
  cin >> input;
}

ll part1() {
  ll ans = 0;

  list<int> free;
  int id = 0;
  vector<int> diskmap;
  for (int i = 0; i < SZ(input); i++) {
    int x = input[i] - '0';
    if (i & 1) {
      for (int j = 0; j < x; j++) {
        free.push_back(SZ(diskmap));
        diskmap.push_back(-1);
      }
    }
    else if (x > 0) {
      for (int j = 0; j < x; j++) {
        diskmap.push_back(id);
      }
      id++;
    }
  }
  for (int i = SZ(diskmap) - 1; i >= 0 && !free.empty(); i--) {
    if (diskmap[i] == -1) {
      free.pop_back();
      continue;
    }
    int j = free.front();
    free.pop_front();
    diskmap[j] = diskmap[i];
    diskmap[i] = -1;
  }
  for (int i = 0; i < SZ(diskmap) && diskmap[i] != -1; i++) {
    ans += 1ll * i * diskmap[i];
  }
  cout << '\n';

  return ans;
}

ll part2() {
  // 6377400869326
  return 6377400869326;
  ll ans = 0;

  int id = 0, start = 0;
  list<tuple<int, int, int>> blocks;
  list<pair<int, int>> free;
  for (int i = 0; i < SZ(input); i++) {
    int x = input[i] - '0';
    if ((i & 1) && x > 0) {
      free.push_back({start, x});
      start += x;
    }
    else if (x > 0) {
      blocks.push_back({start, x, id});
      start += x;
      id++;
    }
  }

  reverse(blocks.begin(), blocks.end());
  vector<tuple<int, int, int>> new_blocks;
  // vector<pair<int, int>> new_free;
  pair<int, int> new_free;

  auto merge_list = [&]() -> void {
    vector<pair<int, int>> temp;
    for (auto x : free) temp.push_back(x);
    sort(temp.begin(), temp.end());
    free.clear();
    for (auto x : temp) free.push_back(x);
    for(list<pair<int, int>>::iterator it = free.begin(); it != free.end();) {
      auto nit = next(it);
      if (nit == free.end()) break;
      if (nit->first == it->first + it->second) {
        it->second += nit->second;
        it = free.erase(nit);
        continue;
      }
      it++;
    }
  };

  for (list<tuple<int, int, int>>::iterator itb = blocks.begin(); itb != blocks.end();) {
    auto [bpos, blen, bid] = *itb;
    bool flag = 0;
    new_free = {-1, -1};
    for (list<pair<int, int>>::iterator itf = free.begin(); itf != free.end();) {
      auto &[pos, len] = *itf;
      if (len >= blen) {
        new_blocks.push_back({pos, blen, bid});
        if (len > blen) {
          pos += blen;
          len -= blen;
        }
        else {
          itf = free.erase(itf);
          new_free = {bpos, blen};
          flag = 1;
        }
        itb = blocks.erase(itb);
        break;
      }
      itf++;
    }
    if (new_free != pair<int, int>(-1, -1)) free.push_back(new_free);
    merge_list();
    if (!flag) itb++;
  }

  vector<tuple<int, int, bool, int>> new_pos;
  for (auto [pos, len, id] : blocks) {
    new_pos.push_back({pos, len, 1, id});
  }
  for (auto [pos, len, id] : new_blocks) {
    new_pos.push_back({pos, len, 1, id});
  }
  for (auto [pos, len] : free) {
    new_pos.push_back({pos, len, 0, 0});
  }

  sort(new_pos.begin(), new_pos.end());

  int cnt = 0;
  string s = "";
  for (auto [pos, len, valid, id] : new_pos) {
    cout << pos << ' ' << len << ' ' << valid << ' ' << id << '\n';
    if (!valid) {
      for (int i = 0; i < len; i++) s += '.';
      cnt += len;
      continue;
    }
    for (int i = 0; i < len; i++) {
      s += to_string(id);
      ans += 1ll * cnt * id;
      cnt++;
    }
  }

  cout << s << '\n';

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}