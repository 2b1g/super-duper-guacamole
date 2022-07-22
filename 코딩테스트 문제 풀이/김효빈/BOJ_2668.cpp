#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int n,x,cur;
vector<int> vc[105];
vector<int> ans;
set<int> ansCnt;
vector<int> tmp;
bool cant[105];
bool check[105];
bool ansCheck[105];
void dfs(int cnt) {
	tmp.push_back(cnt);
	check[cnt] = 1;
	for (int i = 0; i <1; i++) {
		int nxt = vc[cnt][0];
		if (check[nxt] == 1 && nxt == cur) { //순회 가능 
			for (auto e : tmp) {
				cant[e] = 1;
				ans.push_back(e);
				ansCnt.insert(e);
				return;
			}
		}
		else if (check[nxt] == 1 && nxt != cur) {
			cant[cur] = 1;
			return;
		}
		else {
			dfs(nxt);
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		vc[i].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (cant[i]) continue;
		cur = i;
		dfs(i);
		fill(check, check + 105, 0);
		tmp.clear();
	}
	cout << ansCnt.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto e : ans) {
		if (!ansCheck[e]) {
			cout << e << "\n";
			ansCheck[e] = 1;
		}
	}
	
}
	
