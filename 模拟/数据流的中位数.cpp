#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
priority_queue<long int> nums;
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		char s;
		cin >> s;
		switch (s)
		{
		case'+':
			int num;
			cin >> num;
			nums.push(num);
			break;
		case'?':
			priority_queue<long int> temp=nums;
			int length = temp.size();	
			if (length == 1)
			{
				cout << temp.top() << endl;
				break;
			}
			if (length % 2 == 0)
			{
				for (int i = 0;i < length / 2-1;i++)
					temp.pop();
				int a1 = temp.top();
				temp.pop();
				int a2 = temp.top();
				double ans = 0.5 * (a1 + a2);
				cout <<ans <<endl;
			}
			else {
				for (int i = 0;i < length / 2;i++)
					temp.pop();
				cout << temp.top()<<endl;
			}
			
			break;
			
		}
	}
	return 0;
}