//MT2068  ���������ˣ��ֵ�����ѧ��ʦ�Ѱ��ʱ����ѧ��ʦ����ͬѧһ�ѣ�������Ҫһ���ظ�ĳЩͬѧ���ӷ���(��Ϊ������)����Ҫע����ͷ��Ƕ��١�
//���ڹ������ܴ����ܰ������ ?
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 5e6 + 10;
int main()
{
	int n, p;
	int ans = 999999;
	cin >> n>>p;
	int grade[N];
	grade[0] = 0;
	int sub[N];
	for (int i = 1;i <= n;i++)
	{
		cin >> grade[i];
		sub[i] = grade[i] - grade[i - 1];//�������
	}
	while (p--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		sub[x] += z;
		sub[y+1] -= z;//��ֲ����Ĺ�ʽ

	}
	for (int i = 1;i <= n;i++)
	{
		grade[i] = grade[i - 1] + sub[i];
		ans = min(ans, grade[i]);
	}
	cout << ans;
	return 0;
	
}
