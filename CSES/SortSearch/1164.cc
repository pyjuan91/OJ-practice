#include <bits/stdc++.h>
using namespace std;
class Customer {
	public:
		int arrive_time, leave_time, index;
		Customer(int _arrive_time, int _leave_time, int _index) {
			arrive_time = _arrive_time;
			leave_time = _leave_time;
			index = _index;
		}
		bool operator<(const Customer& other) const {
			if (arrive_time == other.arrive_time)
				return leave_time < other.leave_time;
			return arrive_time < other.arrive_time;
		}
};
class Room {
	public:
		int available_time, room_id;
		Room(int _available_time, int _room_id) {
			available_time = _available_time;
			room_id = _room_id;
		}
};
bool operator<(const Room& a, const Room& b) {
	if (a.available_time == b.available_time)
		return a.room_id > b.room_id;
	return a.available_time > b.available_time;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, a, b, res = 1;
    cin >> n;
	vector<Customer> customers;
	priority_queue<Room> room_queue;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		customers.emplace_back(Customer(a, b, i));
	}
	room_queue.push(Room(0, 1));
	sort(begin(customers), end(customers));
	for (auto& customer : customers) {
		if (customer.arrive_time > room_queue.top().available_time) {
			ans[customer.index] = room_queue.top().room_id;
			room_queue.push(Room(
			  customer.leave_time, room_queue.top().room_id));
			room_queue.pop();
		}
		else {
			res += 1;
			ans[customer.index] = res;
			room_queue.push(Room(customer.leave_time, res));
		}
	}
	cout << res << "\n";
	for (auto& x : ans) cout << x << " ";
	return 0;
}