/*
ѧ��Ȳ����е�С���������ˬ��������һ���������ҵ��Ȳ�Ĳ��֡�������һ����������nums��
Ҫ�������������Ϊ�Ȳ���������������(�Ȳ����������飬ָ��������3��������������ɵȲ�����)��
*/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> nums;
int cal(int length)
{
	int n = length - 1;
	int sum = 0;
	while (n--)
	{
		sum += n;
	}
	return sum;
}
int main()
{
	int a;
	int ans = 0;
	while (cin>>a)
	{
		nums.push_back(a);
	}
	int sub[5050] = {};
	sub[0] = 0;
	
	for (int i = 1;i < nums.size();i++)
	{
		sub[i] = nums[i] - nums[i - 1];//����������
	}
	for (int i = 1;i < nums.size();)
	{
		int length = 1;
		if (sub[i] == sub[i - 1])
		{
			int current = i;
			while (sub[current] == sub[i])
			{
				current++;
				length++;
			}
			if (length >= 2)
			{
				ans += cal(length + 1);//����Ϊlength+1�ĵȲ������а����ĳ��ȴ���3�ĵȲ������и���
			}
			i = current;
		}
		else {
			i++;
		}
	}
	cout << ans;
	
	return 0;
}