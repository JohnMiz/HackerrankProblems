#include "pch.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {

	 int m, n;

	 std::cin >> m >> n;

	 std::vector<int> vecA(m);
	 std::vector<int> vecB(n);

	 int** memo = new int*[m + 1];

	 for (int i = 0; i < m + 1; ++i)
	 {
		  memo[i] = new int[n + 1];
		  for (int j = 0; j < n + 1; ++j)
		  {
			   memo[i][j] = 0;
		  }
	 }

	 for (int i = 0; i < m; ++i)
	 {
		  cin >> vecA[i];
	 }


	 for (int i = 0; i < n; ++i) {
		  cin >> vecB[i];
	 }


	 for (int i = 0; i < m; ++i)
	 {
		  for (int j = 0; j < n; ++j)
		  {
			   if (vecA[i] == vecB[j])
			   {
					memo[i + 1][j + 1] = memo[i][j] + 1;
			   }
			   else
			   {
					memo[i + 1][j + 1] = std::max(memo[i][j + 1], memo[i + 1][j]);
			   }
		  }
	 }
		  
	 std::vector<int> res;

	 int i = m, j = n;
	 while (i && j)
	 {
		  if (memo[i][j] == memo[i][j - 1])
			   j--;
		  else if (memo[i][j] == memo[i - 1][j])
			   i--;
		  else if (memo[i][j] == memo[i - 1][j - 1] + 1)
		  {
			   i--;
			   j--;
			   res.push_back(vecB[j]);   
		  }
	 }

	 for (int i = res.size() - 1; i >= 0; --i)
	 {
		  std::cout << res[i] << " ";
	 }

	 for (int i = 0; i < m; ++i) {
		  delete[] memo[i];
	 }

	 return 0;
}