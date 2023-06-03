/*
������״�����������
1.��ɢ��
2.��˳��ԣ��������+��ѯ��
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200010;
int nums[N], c[N], seperate[N];//nums��ԭ���飬seperate�ǽ�����ɢ�����飬C����״����
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
bool cmp(int x, int y)
{
	if (nums[x] == nums[y])
		return x > y;
	return nums[x] > nums[y];
}
int main()
{
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> nums[i];
		seperate[i] = i;//��ʼ����ɢ����
	}
	sort(seperate + 1, seperate + n + 1, cmp);
	for (int i = 1;i <= n;i++)
	{
		add(seperate[i], 1);
		ans += sum(seperate[i] - 1);
	}
	cout << ans;
	return 0;
}