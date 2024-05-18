#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  struct Card {
    int strength, cost, id;
    Card(int strength, int cost, int id)
        : strength(strength), cost(cost), id(id) {}
    Card() {}
  };

  vector<Card> cards(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cards[i] = Card(a, b, i);
  }

  sort(cards.begin(), cards.end(),
       [](const Card &a, const Card &b) { return a.strength > b.strength; });

  vector<bool> is_discarded(n, false);
  int min_cost = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (cards[i].cost > min_cost) {
      is_discarded[cards[i].id] = true;
    } else {
      min_cost = min(min_cost, cards[i].cost);
    }
  }
  // sort(cards.begin(), cards.end(),
  //      [](const Card &a, const Card &b) { return a.cost < b.cost; });

  // int max_strength = 0;
  // for (int i = 0; i < n; i++) {
  //   if (cards[i].strength < max_strength) {
  //     is_discarded[cards[i].id] = true;
  //   } else {
  //     max_strength = max(max_strength, cards[i].strength);
  //   }
  // }

  int remain_cards = 0;
  for (int i = 0; i < n; i++) {
    if (!is_discarded[i]) {
      remain_cards++;
    }
  }

  cout << remain_cards << '\n';
  for (int i = 0; i < n; i++) {
    if (!is_discarded[i]) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
