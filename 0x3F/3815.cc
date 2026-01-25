#include <bits/stdc++.h>
using namespace std;

class AuctionSystem {
 private:
  // [userId, [itemId, bidAmount]]
  unordered_map<int, unordered_map<int, int>> bid_record;
  // [itemId, [bidAmount, userId]]
  unordered_map<int, set<pair<int, int>>> markets;

 public:
  AuctionSystem() {
    bid_record.clear();
    markets.clear();
  }

  void addBid(int userId, int itemId, int bidAmount) {
    if (bid_record.count(userId) and bid_record[userId].count(itemId)) {
      int old_bid = bid_record[userId][itemId];
      markets[itemId].erase(make_pair(old_bid, userId));
    }
    bid_record[userId][itemId] = bidAmount;
    markets[itemId].insert(make_pair(bidAmount, userId));
  }

  void updateBid(int userId, int itemId, int newAmount) {
    addBid(userId, itemId, newAmount);
  }

  void removeBid(int userId, int itemId) {
    int bid = bid_record[userId][itemId];
    bid_record[userId].erase(itemId);
    markets[itemId].erase(make_pair(bid, userId));
  }

  int getHighestBidder(int itemId) {
    if (!markets.count(itemId) or markets[itemId].empty()) return -1;
    return (*markets[itemId].rbegin()).second;
  }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */

int main() { return 0; }