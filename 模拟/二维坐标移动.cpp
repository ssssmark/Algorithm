#include<iostream>
using namespace std;
int main()
{
	int N, M, K;
	cin >> N >> M;
	int a[55][55];
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
			cin >> a[i][j];
	}
	cin >> K;
	while (K--)
	{
		int first = a[0][0];
		a[0][0] = a[N - 1][M - 1];
		int last[100];
		int index = 0;
		for (int i = 0;i <= N - 2;i++)
		{
			last[index++] = a[i][M - 1];
		}

		for (int i = 0;i < N;i++)
		{
			for (int j = M - 2;j >= 0;j--)
			{
				a[i][j + 1] = a[i][j];
			}
		}
		a[0][1] = first;
		index = 0;
		for (int i = 0;i <= N - 2;i++)
		{
			a[i + 1][0] = last[index++];
		}
		

	}
	
	
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	
	return 0;
}