#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		bool val;
		bool isLeaf;
		Node* topLeft;
		Node* topRight;
		Node* bottomLeft;
		Node* bottomRight;

		Node() {
			val = false;
			isLeaf = false;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(bool _val, bool _isLeaf) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(
			bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
			Node* _bottomLeft, Node* _bottomRight) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
};

class Solution {
	public:
		Node* construct(vector<vector<int>>& grid) {
			int n = grid.size();
			Node* res = new Node();
			if (n == 1)
				return new Node(grid[0][0], true);

			bool same = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] != grid[0][0]) {
						same = false;
						break;
					}
				}
			}
			if (same) return new Node(grid[0][0], true);
			else res->isLeaf = false;

			vector<vector<int>> qua(n / 2, vector<int>(n / 2));
			for (int i = 0; i < n / 2; i++)
				for (int j = 0; j < n / 2; j++)
					qua[i][j] = grid[i][j];
			res->topLeft = construct(qua);
			for (int i = 0; i < n / 2; i++)
				for (int j = n / 2; j < n; j++)
					qua[i][j - n / 2] = grid[i][j];
			res->topRight = construct(qua);
			for (int i = n / 2; i < n; i++)
				for (int j = 0; j < n / 2; j++)
					qua[i - n / 2][j] = grid[i][j];
			res->bottomLeft = construct(qua);
			for (int i = n / 2; i < n; i++)
				for (int j = n / 2; j < n; j++)
					qua[i - n / 2][j - n / 2] = grid[i][j];
			res->bottomRight = construct(qua);
			return res;
		}
};
int main() { return 0; }