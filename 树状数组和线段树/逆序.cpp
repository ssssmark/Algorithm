//MT2142
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int nums[N], c[N],chg[N];//c[N]Ϊ��״����,chg[i]����ɾ��iԪ�ض���������record�Ĺ���
int n;
int lowbit(int x)
{
	return x & -x;
}
void add(int i, int x)//����£��ӵײ�һֱ���¸��ڵ㵽����
{
	for (;i <= n;i += lowbit(i))
		c[i] += x;
}
int sum(int i)//����1-i�������
{
	int ans = 0;
	for (;i > 0;i -= lowbit(i))
		ans += c[i];
	return ans;
}
int main()
{
	cin >> n;
	int x = 0, maxx = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> x;
		maxx = max(x, maxx);
		int smaller = sum(x);//��״�����ѯ�����ǰ���ж���������С
		if (smaller == i - 1)//i-1��˵����ǰ��Ϊǰi�������ֵ
		{
			chg[maxx]--;
		}
		else if (smaller == i - 2)
		{
			chg[maxx]++;//i-2��˵��ǰ����1�����ȵ�ǰ������ô����������ɾ������ǰ���Ϳ��Գ�Ϊһ��record
		}
		add(x, 1);
		
	}
	int ans = 1;
	for (int i = 1;i <= n;i++)
	{
		if (chg[i] > chg[ans])
			ans = i;
	}
	cout << ans;
	return 0;
}