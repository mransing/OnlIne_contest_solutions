/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     CHEFHACK - End Of The World
 * Author:      Anton Lunyov (Tester and Editorialist)
 * Complexity:  O(K * log log K + T * N * N), where K = 10^7-1 is the maximal possible password
 * Timing:      0.30 out of 2.00
 *
 * Description:
 * We find all primes up to 10^7 using Eratosthenes Sieve
 * Then in a single pass find the cost of each prime
 * as well as cost of all other numbers
 * (refer to editorial for the definition of cost)
 * Then for each test we traverse the grid on row-major order
 * and for each unvisited cell add it cost to the answer
 * and if it not prime run DFS from it to find its connected component
 * and mark all cells there as visited
 */
#include <iostream>
#include <stdio.h>
using namespace std;

const int K = 10000000;
bool isPrime[K];
int cost[K];

const int maxN = 350;
int n;
int a[maxN][maxN];
bool visited[maxN][maxN];

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

void dfs(int i, int j) {

  visited[i][j] = 1;

  // loop over neigbors of the cell
  for (int k = 0; k < 4; ++k) {

	// arrays dx[] and dy[] contain shifts
	// that need to be applied to the cell coordinates
	// to get its neighbors
	int x = i + dx[k];
	int y = j + dy[k];

	// if the cell (x,y) is outside the grid we skip it
	if (x < 0 || x >= n || y < 0 || y >= n) continue;

	// if the cell (x,y) was visited before we skip it
	if (visited[x][y]) continue;

	// if the cell (x,y) contains prime number we can't pass to it
	if (isPrime[a[x][y]]) continue;

	// if the cell (x,y) contains the number
	// of different parity than cell (i,j) we also can't pass to it
	if (a[x][y] % 2 != a[i][j] % 2) continue;

	// finally we pass to the cell if it is good
	dfs(x,y);
  }
}

int main() {

  // we mark all numbers >= 2 as potential primes
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < K; ++i) {
	isPrime[i] = true;
  }

  // Sieve of Eratosthenes 
  for (int i = 2; i * i < K; ++i) {
	if (isPrime[i]) {
	  // iteration over numbers having i as a prime factor
	  // we use heuristic to start from i^2
	  // it speed ups the sieve twice
	  for (int j = i * i; j < K; j += i) {
		isPrime[j] = false;
	  }
	}
  }

  // calculation of cost
  int prime_id = 0;
  for (int i = 0; i < K; ++i) {
	if (isPrime[i]) {
	  cost[i] = prime_id++;
	} else {
	  cost[i] = i / 2 + (i % 2) * 2;
	}
  }

  // input number of tests
  int T;
  scanf("%d", &T); // we use scanf to do input faster

  // loop over tests
  for (int t = 0; t < T; ++t) {

	// input n, grid and init visited
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
	  for ( int j = 0; j < n; ++j) {
		scanf("%d", &a[i][j]);
		visited[i][j] = false;
	  }
	}

	// traversing the grid
	long long total_cost = 0;
	for (int i = 0; i < n; ++i) {
	  for (int j = 0; j < n; ++j) {

		// we skip already visited cells
		if (visited[i][j]) {
		  continue;
		}

		// updte the total_cost
		int x = a[i][j];
		total_cost += cost[x];

		// if the number in the cell is non-prime we run dfs
		if (!isPrime[x]) {
		  dfs(i, j);
		}
	  }
	}

	// output the result
	cout << total_cost << endl;
  }
  return 0;
}
