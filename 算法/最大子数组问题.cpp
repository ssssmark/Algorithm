/*����������һ�����飬�����е�Ԫ���������͸�����������������ҵ�һ�������������飬ʹ�����������Ԫ��֮�����*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
struct Status {
	int low,high,sum;
};
Status find_crossing_mid_array(int low,int mid,int high)
{
	//����mid����߽߱�����
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
	//����mid���ұ߽߱�����
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
		return one;//��ʱ�����ε�����ֻ��һ��Ԫ��
	}
	else {
		int mid = (low + high) / 2;
		l = find_max_subarray(low, mid);
		r=  find_max_subarray(mid+1, high);
		m = find_crossing_mid_array(low, mid,high);//�������
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