#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
vector<int> makeVec(vector<int>& vec)
{
	vector<int> v;
	for (int i = 0; i < (1 << vec.size()); i++)
	{
		int num = 0;
		for (int j = 0; j < vec.size(); j++)
		{
			if (i & (1 << j)) {
				num += vec[j];
			}
		}
		v.push_back(num);
	}
	v.erase(v.begin());
	sort(v.begin(), v.end());
	return v;
}
int main()
{
	vector<int> pos, neg;
	int count;
	cin >> count;
	for (int i = 0; i < count ; i++)
	{
		int a;
		cin >> a;
		if (a >= 0) pos.push_back(a);
		else neg.push_back(a);
	}
	vector<int> posSum, negSum;
	posSum = makeVec(pos);
	negSum = makeVec(neg);
	for (int i : posSum) printf("%d, ", i);
	printf("\n");
	for (int i : negSum) printf("%d, ", i);
	printf("\n");
	int front = 0;
	int back = negSum.size() - 1;

	int index = 0;

	while (front < posSum.size() && back>=0)
	{
		int num = posSum[front] + negSum[back];

		if (num == 0)
		{
			index++;
			if (front < posSum.size() - 2) {

			if (posSum[front + 1] == posSum[front])
			{
				index++;
			}
			}
			if (back > 0) {

			if (negSum[back] == negSum[back - 1]) {
				index++;
			}
			}
			front++;
			back--;
		}
		else if (num < 0)
		{
			front++;
		}
		else if (num > 0)
		{
			back--;
		}
	}
	printf("count : %d", index);
}

