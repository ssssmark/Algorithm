#include<iostream>
#include<map>
using namespace std;
map<int, int> Hash;//��ֵ��<���֣����ִ���>
int main()
{
	int n, C;
	cin >> n >> C;
	long long ans = 0;
	int* nums = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> nums[i];
		Hash[nums[i]]++;
		nums[i] -= C; //A-B=C ��Ч��A-C=B��ֻ�����ÿһ�����ֵ�A-C�����ж���B����Ҫ��
	}
	for (int i = 0;i <= n;i++)
	{
		ans += Hash[nums[i]];//B���ֶ��ٴν���ͼӶ���
	}
	cout << ans << endl;
	return 0;
}