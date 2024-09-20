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
int roaddx[] = { -1, 0, 0, 1 };
int roaddy[] = { 0, -1, 1, 0 };

void init() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

CD findMin() {
	vector<CD> V;
	int Min = INT_MAX;
	for (int x = M; x > 0; x--) {
		for (int y = N; y > 0; y--) {
			if (board[y][x] == 0) continue;
			Min = min(Min, board[y][x]);
		}
	}
	for (int x = M; x > 0; x--) {
		for (int y = N; y > 0; y--) {
			if (board[y][x] == Min) V.push_back({ x, y });
		}
	}
	if (V.size() == 1) return V[0];
	else {
		vector<CD> tmp;
		int Max = attack[V[0].Y][V[0].X];
		for (int i = 0; i < V.size(); i++) {
			Max = max(Max, attack[V[i].Y][V[i].X]);
		}
		for (int i = 0; i < V.size(); i++) {
			if (attack[V[i].Y][V[i].X] == Max) tmp.push_back({ V[i].X, V[i].Y });
		}
		if (tmp.size() == 1) return tmp[0];
		else {
			vector<int> A;
			for (int i = 0; i < tmp.size(); i++) {
				A.push_back(tmp[i].X + tmp[i].Y);
			}
			Max = INT_MIN;
			for (int i : A) {
				Max = max(Max, i);
			}
			vector<CD> B;
			for (int i = 0; i < A.size(); i++) {
				if (Max == A[i]) B.push_back(tmp[i]);
			}
			if (B.size() == 1) return B[0];
			else {
				Max = INT_MIN;
				vector<CD> C;
				for (int i = 0; i < B.size(); i++) {
					Max = max(Max, B[i].X);
				}
				for (int i = 0; i < B.size(); i++) {
					if (Max == B[i].X) return B[i];
				}
			}
		}
	}
}

CD findMax() {
	vector<CD> V;
	int Max = INT_MIN;
	for (int x = 1; x <= M; x++) {
		for (int y = 1; y <= N; y++) {
			if (board[y][x] == 0) continue;
			Max = max(Max, board[y][x]);
		}
	}
	for (int x = 1; x <= M; x++) {
		for (int y = 1; y <= N; y++) {
			if (board[y][x] == Max) V.push_back({ x, y });
		}
	}
	if (V.size() == 1) return V[0];
	else {
		vector<CD> tmp;
		int Min = attack[V[0].Y][V[0].X];
		for (int i = 0; i < V.size(); i++) {
			Min = min(Min, attack[V[i].Y][V[i].X]);
		}
		for (int i = 0; i < V.size(); i++) {
			if (attack[V[i].Y][V[i].X] == Min) tmp.push_back({ V[i].X, V[i].Y });
		}
		if (tmp.size() == 1) return tmp[0];
		else {
			vector<int> A;
			for (int i = 0; i < tmp.size(); i++) {
				A.push_back(tmp[i].X + tmp[i].Y);
			}
			Min = INT_MAX;
			for (int i : A) {
				Min = min(Min, i);
			}
			vector<CD> B;
			for (int i = 0; i < A.size(); i++) {
				if (Min == A[i]) B.push_back(tmp[i]);
			}
			if (B.size() == 1) return B[0];
			else {
				Min = INT_MAX;
				vector<CD> C;
				for (int i = 0; i < B.size(); i++) {
					Min = min(Min, B[i].X);
				}
				for (int i = 0; i < B.size(); i++) {
					if (Min == B[i].X) return B[i];
				}
			}
		}
	}
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
			if (board[ny][nx] == 0) continue;
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
		if (x == Start.X && y == Start.Y) break;
		road.push_back(past[y][x]);
		CD tmp = past[y][x];
		x = tmp.X;
		y = tmp.Y;
	}
	reverse(road.begin(), road.end());
	return road;
}

void bombAttack(CD Start, CD End, int K) {
	board[End.Y][End.X] -= board[Start.Y][Start.X] + N + M;
	if (board[End.Y][End.X] < 0) board[End.Y][End.X] = 0;
	for (int dir = 0; dir < 8; dir++) {
		int nx = End.X + bombdx[dir];
		int ny = End.Y + bombdy[dir];
		if (nx > M) nx = 1;
		if (nx < 1) nx = M;
		if (ny > N) ny = 1;
		if (ny < 1) ny = N;
		if (board[ny][nx] == 0) continue;
		board[ny][nx] -= board[Start.Y][Start.X] + N + M;
		if (board[End.Y][End.X] < 0) board[End.Y][End.X] = 0;
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
	cout << findAnswer() - 1;
	return 0;
}