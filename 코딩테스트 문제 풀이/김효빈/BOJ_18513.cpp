#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;

int n, k, tmp, cnt;
long long int ans;
unordered_set<int> s;
int x[2] = { -1,1 };
queue<int> q;
long long int bfs() {
	
	int dist = 0;

	while (!q.empty())
	{
		dist++;
		int q_size = q.size();
		while (q_size--)
		{
			int cur = q.front(); q.pop();
			for (int i = 0; i < 2; i++) {
				int nx = cur + x[i];

				if (!(s.count(nx) >= 1)) { //셋에 존재하지 않는경우 
					ans += dist;
					cnt++;
					q.push(nx);
					s.insert(nx);
					
					if (cnt == k)
						return ans;
				}
			}
		}
		
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) { //샘물위치 
		cin >> tmp;
		q.push(tmp);
		s.insert(tmp);
	}

	cout << bfs() << "\n";

}