#include<iostream>
#include<map>
using namespace std;
map<int, int> Hash;//键值对<数字，出现次数>
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
		nums[i] -= C; //A-B=C 等效于A-C=B，只需遍历每一个出现的A-C，看有多少B符合要求
	}
	for (int i = 0;i <= n;i++)
	{
		ans += Hash[nums[i]];//B出现多少次结果就加多少
	}
	cout << ans << endl;
	return 0;
}