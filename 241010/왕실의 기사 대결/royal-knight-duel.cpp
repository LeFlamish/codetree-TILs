#include <bits/stdc++.h>
using namespace std;

struct Knight {
	int x;
	int y;
	int h;
	int w;
	int k;
};

int L, N, Q, ret;
int board[2][41][41];
int origin[31];
Knight knight[31];
int order[100][2];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void check(int q) {
	cout << "====================\n";
	cout << q + 1 << "번 째\n";
	cout << "--------------------\n";
	cout << "함정과 벽\n";
	for (int y = 1; y <= L; y++) {
		for (int x = 1; x <= L; x++) {
			cout << board[0][y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	cout << "기사들\n";
	for (int y = 1; y <= L; y++) {
		for (int x = 1; x <= L; x++) {
			cout << board[1][y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "현재 점수 : " << ret << '\n';
	cout << "====================\n";
}

void init() {
	cin >> L >> N >> Q;
	for (int y = 1; y <= L; y++) {
		for (int x = 1; x <= L; x++) {
			cin >> board[0][y][x];
		}
	}
	for (int n = 1; n <= N; n++) {
		cin >> knight[n].y >> knight[n].x >> knight[n].h >> knight[n].w >> knight[n].k;
		origin[n] = knight[n].k;
		for (int y = 0; y < knight[n].h; y++) {
			for (int x = 0; x < knight[n].w; x++) {
				board[1][knight[n].y + y][knight[n].x + x] = n;
			}
		}
	}
	for (int q = 0; q < Q; q++) {
		cin >> order[q][0] >> order[q][1];
	}
}

bool canMove(int nx, int ny) {
	if (nx < 1 || nx > L || ny < 1 || ny > L) return false;
	if (board[0][ny][nx] == 2) return false;
	return true;
}

bool interaction(int Num, int nx, int ny, int dir) {
    bool flag = false;
	int knightNum = board[1][ny][nx];
	Knight tmp = knight[knightNum];
	for (int y = 0; y < tmp.h; y++) {
		for (int x = 0; x < tmp.w; x++) {
			int nx = tmp.x + x + dx[dir];
			int ny = tmp.y + y + dy[dir];
			if (!canMove(nx, ny)) flag = true;
			if (board[1][ny][nx] > 0 && board[1][ny][nx] != knightNum) {
				if (!interaction(knightNum, nx, ny, dir)) flag = true;
			}
		}
	}
    if (flag) return false;
	for (int y = 0; y < knight[knightNum].h; y++) {
		for (int x = 0; x < knight[knightNum].w; x++) {
			board[1][knight[knightNum].y + y][knight[knightNum].x + x] = 0;
		}
	}
	knight[knightNum].x += dx[dir];
	knight[knightNum].y += dy[dir];
	int damage = 0;
	for (int y = 0; y < knight[knightNum].h; y++) {
		for (int x = 0; x < knight[knightNum].w; x++) {
			board[1][knight[knightNum].y + y][knight[knightNum].x + x] = knightNum;
			if (board[0][knight[knightNum].y + y][knight[knightNum].x + x] == 1) damage++;
		}
	}
	knight[knightNum].k -= damage;
	if (knight[knightNum].k <= 0) {
		for (int y = 0; y < knight[knightNum].h; y++) {
			for (int x = 0; x < knight[knightNum].w; x++) {
				board[1][knight[knightNum].y + y][knight[knightNum].x + x] = 0;
			}
		}
	}
	return true;
}

void move(int k) {
    bool flag = false;
	int knightNum = order[k][0];
	int knightDir = order[k][1];
	Knight tmp = knight[knightNum];
	for (int y = 0; y < tmp.h; y++) {
		for (int x = 0; x < tmp.w; x++) {
			int nx = tmp.x + x + dx[knightDir];
			int ny = tmp.y + y + dy[knightDir];
			if (!canMove(nx, ny)) flag = true;
			if (board[1][ny][nx] > 0 && board[1][ny][nx] != knightNum) {
				if (!interaction(knightNum, nx, ny, knightDir)) flag = true;
			}
		}
	}
    if (flag) return;
	for (int y = 0; y < knight[knightNum].h; y++) {
		for (int x = 0; x < knight[knightNum].w; x++) {
			board[1][knight[knightNum].y + y][knight[knightNum].x + x] = 0;
		}
	}
	knight[knightNum].x += dx[knightDir];
	knight[knightNum].y += dy[knightDir];
	if (board[1][knight[knightNum].y][knight[knightNum].x] > 0 && board[1][knight[knightNum].y][knight[knightNum].x] != knightNum) {
		knight[knightNum].x -= dx[knightDir];
		knight[knightNum].y -= dy[knightDir];
	}
	else {
		for (int y = 0; y < knight[knightNum].h; y++) {
			for (int x = 0; x < knight[knightNum].w; x++) {
				board[1][knight[knightNum].y + y][knight[knightNum].x + x] = knightNum;
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	for (int q = 0; q < Q; q++) {
		//check(q);
		move(q);
		//check(q);
	}
	for (int n = 1; n <= N; n++) {
		if (knight[n].k > 0) ret += origin[n] - knight[n].k;
	}
	cout << ret;
	return 0;
}