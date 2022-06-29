#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int low = UINT16_MAX;
	int index = 0;
	int count = 0;
	int num;
	cin >> num;

	vector<vector<int>> matrix;
	for (int i = 0; i < num; i++)
	{
		vector<int> vec;
		for (int j = 0; j < num; j++)
		{
			int a;
			scanf_s("%d", &a);
			vec.push_back(a);
			if (low > a && a > 0)
			{
				index = i;
			}
		}
		matrix.push_back(vec);
	}

	/*for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			int a = matrix[i][j];
			printf("%d, ", a);
		}
		printf("\n");
	}*/

	
	bool isCheck[16] = { 0 };
	vector<int> start = matrix[index];
	int answer = 0;
	while (count < num)
	{
		for (int i : start)
		{
			printf("%d, ", i);
		}
		printf("\n");
		int next = INT16_MAX;
		for (int i = 0; i < start.size(); i++)
		{
			if (!isCheck[i])
			{
				if (start[i] < next && start[i] != 0) {
					next = start[i];
					index = i;
				}
			}
		}
		count++;
		printf("ans : %d, next : %d\n", answer, next);
		answer += next;
		start = matrix[index];
		isCheck[index] = 1;
	}
	printf("\n%d", answer);
}