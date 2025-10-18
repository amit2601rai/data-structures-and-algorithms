#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF 1000000000

class BishopMove {
public:
	int howManyMoves(int, int, int, int);
};

int BishopMove::howManyMoves(int r1, int c1, int r2, int c2) {

	map<pair<int,int>,int >m;
	int k = 1;
	for(int i=0; i<=7; i++)for(int j=0; j<=7; j++)m[make_pair(i,j)] = k++;//printf("i=%d j=%d %d\n",i,j,k-1);
	int graph[65][65];
	for(int i=0; i<=64; i++)for(int j=0; j<=64; j++)graph[i][j] = 0;
	for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            for(int u=0; u<=7; u++){
                for(int v=0; v<=7; v++){
                    if(abs(u-i) == abs(v-j))graph[m[make_pair(i,j)]][m[make_pair(u,v)]] = 1;
                }
            }
        }
	}
	int source = m[make_pair(r1,c1)];
	int destination = m[make_pair(r2,c2)];
	queue<int>Q;
	int d[65];
	bool visited[65];
	for(int i=0; i<=64; i++)d[i] = -1,visited[i] = false;
	Q.push(source);
	d[source] = 0;
	visited[source] = true;
	while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i=1; i<=64; i++)if(graph[v][i] == 1 && visited[i] == false)Q.push(i),visited[i]=true,d[i] = d[v]+1;
	}
	return d[destination];
}
