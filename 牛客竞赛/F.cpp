#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct person {
	int t;
	int vote=0;
	int no;
};
bool  cmp(person a, person b)
{
	return a.t < b.t;
}
int main()
{
	int n;
	cin >> n;
	vector<person> a(n+1);
	for (int i = 1;i <=n;i++)
	{
		cin >> a[i].t;
		a[i].no = i;
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0;i < n - 1;i++)
	{
		int end = a.size() - 1;
		a[1].vote++;
		a[end].vote++;
		int 
		for (int j = 2;j <= n -1- i;j++)
		{
			if (a[j].t - a[1].t > a[end].t - a[j].t) {
				a[1].vote++;
			}
			else {
				a[end].vote++;
			}
		}
		int maxvote = a[1].vote;
		int maxi = 1;
		for (int j = 1;j <a.size();j++)
		{
			if (a[j].vote >= maxvote)
			{
				maxvote = a[j].vote;
				maxi = j;
			}
		}
		a.erase(a.begin() + maxi);
		for (int j = 1;j < a.size();j++)
		{
			a[j].vote = 0;
		}
	}
	cout << a[1].no;
	return 0;
}