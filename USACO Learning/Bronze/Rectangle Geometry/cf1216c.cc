#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Rectangle {
	public:
		ll x1, x2, y1, y2;
		Rectangle() { x1 = x2 = y1 = y2 = 0; }
		Rectangle(ll _x1, ll _y1, ll _x2, ll _y2) {
			x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
		}
		ll Area() { return (y2 - y1) * (x2 - x1); }

		ll Intersection(const Rectangle& b) {
			ll diffX = max(0ll, min(b.x2, x2) - max(b.x1, x1));
			ll diffY = max(0ll, min(b.y2, y2) - max(b.y1, y1));
			return diffX * diffY;
		}

		Rectangle GetInterRect(const Rectangle& b) {
			Rectangle res;
			res.x1 = max(b.x1, x1);
			res.x2 = min(b.x2, x2);
			res.y1 = max(b.y1, y1);
			res.y2 = min(b.y2, y2);
			return res;
		}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	Rectangle w, b1, b2, blackCrossing;
	cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
	cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	blackCrossing = b1.GetInterRect(b2);
	bool canNotSeen
		= (w.Intersection(b1) + w.Intersection(b2) - blackCrossing.Intersection(w) == w.Area());
	if (!canNotSeen) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}