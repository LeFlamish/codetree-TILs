#include <bits/stdc++.h>
using namespace std;
#define SIZE 11
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, K;
int board[SIZE][SIZE];
int Prev[SIZE][SIZE];
int attack[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool related[SIZE][SIZE];
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, 1, -1, 1, 1, -1 };

void check(CD Start, CD End) {
	cout << "====================\n";
	cout << Start.X << ' ' << Start.Y << " : " << board[Start.Y][Start.X] - N - M << '\n';
	cout << End.X << ' ' << End.Y << " : " << board[End.Y][End.X] << '\n';
	cout << "--------------------\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	cout << Start.X << ' ' << Start.Y << " : " << board[Start.Y][Start.X] << '\n';
	cout << End.X << ' ' << End.Y << " : " << board[End.Y][End.X] << '\n';
	cout << "====================\n";
}

void init() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> board[y][x];
		}
	}
}

CD findMin() {
	CD ret = { 1, 1 };
	bool flag = false;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] != 0) {
				ret = { x, y };
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] == 0) continue;
			if (board[ret.Y][ret.X] > board[y][x]) {
				ret = { x, y };
			}
			else if (board[ret.Y][ret.X] == board[y][x]) {
				if (attack[ret.Y][ret.X] < attack[y][x]) {
					ret = { x, y };
				}
				else if (attack[ret.Y][ret.X] == attack[y][x]) {
					if (ret.X + ret.Y < x + y) {
						ret = { x, y };
					}
					else if (ret.X + ret.Y == x + y) {
						if (ret.X < x) {
							ret = { x, y };
						}
					}
				}
			}
		}
	}
	board[ret.Y][ret.X] += N + M;
	return ret;
}

CD findMax() {
	CD ret = { 1, 1 };
	bool flag = false;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] != 0) {
				ret = { x, y };
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] == 0) continue;
			if (board[ret.Y][ret.X] < board[y][x]) {
				ret = { x, y };
			}
			else if (board[ret.Y][ret.X] == board[y][x]) {
				if (attack[ret.Y][ret.X] > attack[y][x]) {
					ret = { x, y };
				}
				else if (attack[ret.Y][ret.X] == attack[y][x]) {
					if (ret.X + ret.Y > x + y) {
						ret = { x, y };
					}
					else if (ret.X + ret.Y == x + y) {
						if (ret.X > x) {
							ret = { x, y };
						}
					}
				}
			}
		}
	}
	return ret;
}

bool canLaser(CD Start, CD End) {
	memset(visited, false, sizeof(visited));
	queue<CD> Q;
	visited[Start.Y][Start.X] = true;
	Q.push(Start);
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		if (cur == End) return true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 1) nx = M; if (nx > M) nx = 1;
			if (ny < 1) ny = N; if (ny > N) ny = 1;
			if (board[ny][nx] == 0 || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			Prev[ny][nx] = dir;
			Q.push({ nx, ny });
		}
	}
	return false;
}

void laserAttack(CD Start, CD End) {
	int x = End.X;
	int y = End.Y;
	board[End.Y][End.X] = max(0, board[End.Y][End.X] - board[Start.Y][Start.X]);
	related[End.Y][End.X] = true;
	while (1) {
		int dir = Prev[y][x];
		int nx = x - dx[dir];
		int ny = y - dy[dir];
		if (nx == Start.X && ny == Start.Y) break;
		board[ny][nx] = max(0, board[ny][nx] - board[Start.Y][Start.X] / 2);
		related[ny][nx] = true;
		x = nx; y = ny;
	}
	related[Start.Y][Start.X] = true;
}

void bombAttack(CD Start, CD End) {
	related[Start.Y][Start.X] = true;
	board[End.Y][End.X] = max(0, board[End.Y][End.X] - board[Start.Y][Start.X]);
	related[End.Y][End.X] = true;
	for (int dir = 0; dir < 8; dir++) {
		int nx = End.X + dx[dir];
		int ny = End.Y + dy[dir];
		if (nx < 1) nx = M; if (nx > M) nx = 1;
		if (ny < 1) ny = N; if (ny > N) ny = 1;
		if (board[ny][nx] == 0 || (nx == Start.X && ny == Start.Y)) continue;
		board[ny][nx] = max(0, board[ny][nx] - board[Start.Y][Start.X] / 2);
		related[ny][nx] = true;
	}
}

void prepare() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (board[y][x] && !related[y][x]) board[y][x]++;
		}
	}
}

void solve(int k) {
	CD End = findMax();
	CD Start = findMin();
	
	if (canLaser(Start, End)) laserAttack(Start, End);
	else bombAttack(Start, End);
	attack[Start.Y][Start.X] = k;
	prepare();
	memset(Prev, 0, sizeof(Prev));
	memset(related, false, sizeof(related));
}

int findAnswer() {
	int ret = INT_MIN;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			ret = max(ret, board[y][x]);
		}
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	for (int k = 1; k <= K; k++) {
		solve(k);
	}
	cout << findAnswer();
	return 0;
}