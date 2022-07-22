#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m,a,b;
int relation[5];
vector<int> friends[2001];
bool check[2001];
int ans;
void dfs(int cur,int index) {
	relation[index] = cur;
	check[cur] = 1;
	if (index == 4) {
		ans = 1;
		return;
	}
	for (int i = 0; i < friends[cur].size(); i++) {
		int nxt = friends[cur][i];
		if (!check[nxt]) {
			dfs(nxt, index + 1);
		}
	}
	//안되는경우 check다시 리셋해야됨.
	check[cur] = 0;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		fill(check, check + 2001, 0);
		dfs(i, 0);
		if (ans == 1) {
			cout << ans << "\n";
			//for (int i = 0; i < 5; i++)
				//cout << relation[i] << " ";
			return 0;
		}
	}
	cout << 0 << "\n";
}