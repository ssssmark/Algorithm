/*���εĻ���˼���ǽ�һ����ģΪn������ֽ�Ϊk����ģ��С��������
��Щ�����⻥���������ԭ������ͬ���ݹ������Щ�����⣬Ȼ����Щ������Ľ�ϲ��õ�ԭ����Ľ�
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
		int middle = left + (right - left) / 2;//��ֹ���
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
	std::cout << "�����������б�\n";
	for (int i = 0;i < n;i++)
	{
		int t;
		std::cin >> t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	std::cout << "��������ҵ���\n";
	int x;
	std::cin >> x;
	Bisearch(a, x, n);
	return 0;
}