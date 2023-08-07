#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m, q;
	int ans=0;
	cin >> n >> m >> q;
	int currow = 0, curcol = 0;
	for (int i = 0;i < q;i++)
	{
		string s;
		int num;
		string tag;
		cin >> s >> num >> tag;
		num = num - 1;
		
		if (s == "row")
		{
			if (tag == "on")
			{
				currow++;
				ans += m-curcol;
			}
			else {
				currow--;
				ans -= n-curcol;
			}
		}
		else if(s=="column"){
			if (tag == "on")
			{
				curcol++;
				ans += n-currow;
			}
			else {
				ans -= currow;
			}
		}
	}
	
	cout << ans;
	return 0;
}