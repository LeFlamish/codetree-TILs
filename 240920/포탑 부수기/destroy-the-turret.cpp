#include <bits/stdc++.h>
#define SIZE 11
using namespace std;
typedef pair<int, int> CD;
#define X first
#define Y second

int N, M, K;
int board[SIZE][SIZE];
int attack[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool related[SIZE][SIZE];
CD past[SIZE][SIZE];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int bombdx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int bombdy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

CD findMin() {
	CD ret = { 1, 1 };
	bool flag = false;
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			if (board[y][x] != 0) {
				ret = { x, y };
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			if (board[y][x] == 0) continue;
			if (board[ret.Y][ret.X] > board[y][x]) {
				ret = { x, y };
			}
			else if (board[ret.Y][ret.X] == board[y][x]){
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
	return ret;
}

CD findMax() {
	CD ret = { 1, 1 };
	bool flag = false;
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			if (board[y][x] != 0) {
				ret = { x, y };
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
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
	visited[Start.Y][Start.X];
	Q.push(Start);
	while (!Q.empty()) {
		CD cur = Q.front(); Q.pop();
		if (cur == End) return true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 1) nx = M;
			if (nx > M) nx = 1;
			if (ny < 1) ny = N;
			if (ny > N) ny = 1;
			if (board[ny][nx] == 0 || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			past[ny][nx] = { cur.X, cur.Y };
			Q.push({ nx, ny });
		}
	}
	return false;
}

vector<CD> findRoad(CD Start, CD End) {
	vector<CD> road;
	int x = End.X;
	int y = End.Y;
	while (1) {	
		CD tmp = past[y][x];
		if (tmp.X == Start.X && tmp.Y == Start.Y) break;
		road.push_back(past[y][x]);
		x = tmp.X;
		y = tmp.Y;
	}
	reverse(road.begin(), road.end());
	return road;
}

void bombAttack(CD Start, CD End, int K) {
	board[End.Y][End.X] -= board[Start.Y][Start.X] + N + M;
	if (board[End.Y][End.X] < 0) board[End.Y][End.X] = 0;
	related[Start.Y][Start.X] = true;
	related[End.Y][End.X] = true;
	for (int dir = 0; dir < 8; dir++) {
		int nx = End.X + bombdx[dir];
		int ny = End.Y + bombdy[dir];
		if (nx > M) nx = 1;
		if (nx < 1) nx = M;
		if (ny > N) ny = 1;
		if (ny < 1) ny = N;
		if (board[ny][nx] == 0) continue;
		board[ny][nx] -= (board[Start.Y][Start.X] + N + M) / 2;
		related[ny][nx] = true;
		if (board[ny][nx] < 0) board[ny][nx] = 0;
	}
	attack[Start.Y][Start.X] = K;
}

void laserAttack(CD Start, CD End, int k) {
	vector<CD> road = findRoad(Start, End);
	attack[Start.Y][Start.X] = k;
	related[Start.Y][Start.X] = true;
	for (CD xy : road) {
		board[xy.Y][xy.X] -= (board[Start.Y][Start.X] + N + M) / 2;
		related[xy.Y][xy.X] = true;
		if (board[xy.Y][xy.X] < 0) board[xy.Y][xy.X] = 0;
	}
	board[End.Y][End.X] -= board[Start.Y][Start.X] + N + M;
	if (board[End.Y][End.X] < 0) board[End.Y][End.X] = 0;
	related[End.Y][End.X] = true;
}

void prepare() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!related[i][j] && board[i][j]) board[i][j]++;
		}
	}
}

void solve(int k) {
	memset(related, false, sizeof(related));
	CD Start = findMin();
	CD End = findMax();
	if (canLaser(Start, End)) {
		laserAttack(Start, End, k);
	}
	else {
		bombAttack(Start, End, k);
	}
	prepare();
}

int findAnswer() {
	int ret = INT_MIN;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ret = max(ret, board[i][j]);
		}
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	for (int k = 0; k < K; k++) {
		solve(k);
	}
	cout << findAnswer();
	return 0;
}