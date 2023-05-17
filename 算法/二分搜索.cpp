/*分治的基本思想是将一个规模为n的问题分解为k个规模较小的子问题
这些子问题互相独立且与原问题相同，递归求解这些子问题，然后将这些子问题的解合并得到原问题的解
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
std ::vector<int> a;
void Bisearch(std:: vector <int> a,int x,int n )
{
	int left = 0;int right = n - 1;
	while (left < right)
	{
		int middle = left + (right - left) / 2;//防止溢出
		if (x == a[middle])
		{
			std::cout << "found!,a[" << middle << "]=" << x;
			return;
		}
			
		if (x < a[middle])
			right = middle - 1;
		else if (x > a[middle])
			left = middle + 1;
	}
	std::cout << "not found!";
	return;
}
int main()
{
	int n;
	std::cin >> n;
	std::cout << "请输入有序列表\n";
	for (int i = 0;i < n;i++)
	{
		int t;
		std::cin >> t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	std::cout << "输入想查找的数\n";
	int x;
	std::cin >> x;
	Bisearch(a, x, n);
	return 0;
}