/*
学完等差数列的小码哥神清气爽，他想在一长串数中找到等差的部分。他给你一个整数数组nums，
要求该数组中所有为等差数组的子数组个数(等差数组子数组，指的是至少3个数的连续数组成等差数列)。
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
		sub[i] = nums[i] - nums[i - 1];//构造差分数组
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
				ans += cal(length + 1);//长度为length+1的等差数列中包含的长度大于3的等差子数列个数
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