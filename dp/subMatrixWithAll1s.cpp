#include<bits/stdc++.h>
using namespace std;
#define MAXROW 100
#define MAXCOL 100

int Histogram(int *histo, int n)
{
	/*
		returns the largest area rectangle in a histogram
		Complexity: O(n)
	*/
	stack<int> heights, index;
	int largestArea = 0;

	for(int i = 0; i < n; i++)
	{
		//case 1. current height is larger than that at TOS 
		if(heights.empty() || histo[i] > heights.top())	//or of stack is empty
		{
			heights.push(histo[i]);			
			index.push(i);
		}
		//case 2. current height is less than that at TOS
		else if(histo[i] < heights.top())	
		{
			int lastIndex = 0;
			//if the current height is shorter, we need to pop those longer heights 
			//and compute the current rectangle area
			while(!heights.empty() && histo[i] < heights.top())
			{
				//compute current area
				lastIndex = index.top();
				int tempArea = heights.top() * (i - lastIndex);
				heights.pop(), index.pop();
				largestArea = max(tempArea, largestArea);
			}
			heights.push(histo[i]);
			index.push(lastIndex);
		}
	}
	while(!heights.empty())
	{
		int tempArea = heights.top() * (n - index.top() );
		heights.pop(), index.pop();
		largestArea = max(largestArea, tempArea);
	}
	return largestArea;
}
int M[MAXROW][MAXCOL];
int subMatrixWithAll1s(int ROW, int COL)
{
	/*
		returns the area of largest sub matrix with all 1's
		Complexity: O(n^2)
	*/
	for(int i = 1; i < ROW; i++)
		for(int j = 0; j < COL; j++)
			if(M[i][j] == 1)
				M[i][j] = M[i-1][j] + 1;

	int maxArea = 0;
	for(int i = 0; i < ROW; i++)
	{
		int sum = Histogram(M[i], COL);
		maxArea = max(maxArea, sum);
	}
	return maxArea;

}

int main()
{	
	int ROW, COL;
	scanf("%d %d", &ROW, &COL);
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
		{
			scanf("%d", &M[i][j]);
		}
	int ans = subMatrixWithAll1s(ROW, COL);
	printf("%d\n", ans);
	return 0;
}
