/*假如我们有一个数组，数组中的元素有正数和负数，如何在数组中找到一段连续的子数组，使得子数组各个元素之和最大。*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
struct Status {
	int low,high,sum;
};
Status find_crossing_mid_array(int low,int mid,int high)
{
	//计算mid到左边边界最大和
	int left_sum = INT_MIN;
	int sum = 0;
	int max_left = 0;
	for (int i = mid;i >= low;i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	//计算mid到右边边界最大和
	int right_sum = INT_MIN;
	int max_right = 0;
	sum = 0;
	for (int j = mid + 1;j <= high;j++)
	{
		sum += a[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	Status p;
	p.low = max_left;
	p.high = max_right;
	p.sum = left_sum + right_sum;
	return p;
}
Status find_max_subarray(int low, int high)
{
	Status l, r, m;
	Status one;
	one.high = high;
	one.low = low;
	one.sum = a[low];
	if (low == high)
	{
		return one;//此时被分治的数组只有一个元素
	}
	else {
		int mid = (low + high) / 2;
		l = find_max_subarray(low, mid);
		r=  find_max_subarray(mid+1, high);
		m = find_crossing_mid_array(low, mid,high);//三种情况
		if (l.sum >= r.sum && l.sum >= m.sum)
			return l;
		else if (r.sum >= l.sum && r.sum >= m.sum)
			return r;
		else return m;
	}
	
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	Status ans = find_max_subarray(0, n-1);
	cout << ans.low << " " << ans.high<<" "<<ans.sum;
	return 0;
}