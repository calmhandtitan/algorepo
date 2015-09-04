#include<bits/stdc++.h>
using namespace std;

int Histogram(int *histo, int n)
{
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

int main()
{
	int h[] = {2, 4, 2, 1};
	int ans = Histogram(h, 4);
	cout << ans << endl;
	return 0;
}
