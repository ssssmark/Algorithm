/*
��һ��ֱ������ϵ�ϣ��� n ����������Ԫ��ֵ(���������Ԫ��ֵΪ0)��
�ָ���һЩ������� (ti,yi) ����������Ԫ��ֵ v: ��������һ���߳�Ϊ R ������������ ���Ԫ��ֵ�ĺ͵����ֵ�������������εı߽硣
*/
#include<iostream>
using namespace std;
int map[1005][1005] = {};
int s[1005][1005] = {};//s[i,j]��ʾ��i�е�j�и������Ͻ�����Ԫ�صĺ�
int main()
{
	int n, R;
	cin >> n >> R;
	for (int i = 1;i <=n;i++)
	{
		int x, y, v;
		cin >> x >> y >> v;
		x++;
		y++;
		map[x][y] += v;
	}
	for (int i = 1;i <= 1001;i++)
	{
		for (int j = 1;j <=1001;j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]+map[i][j];
		}
	}
	int ans = 0;
	for (int i =R ;i <= 1001;i++)
	{
		for (int j = R;j <= 1001;j++)
		{
			ans = max(ans, s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
		}
	}
	cout << ans;
}