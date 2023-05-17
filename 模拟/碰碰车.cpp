//https://matiji.net/exam/dohomework/3147/1
#include<iostream>
#include<algorithm>
using namespace std;
struct Car{
	int v = 1;
	int direction;
	float pos;
	int state = -1;
	int id;
}cars[1005];
void check_turn(int n)
{
	for (int i = 0;i < n-1;i++)
	{
		if (cars[i].pos == cars[i + 1].pos)
		{
			cars[i].direction = -cars[i].direction;
			cars[i+1].direction = -cars[i+1].direction;
			cars[i].state = 0;
			cars[i + 1].state = 0;//state=0��ʾ��ײ
		}
		
	}
}
bool comparepos(Car c1, Car c2)
{
	return c1.pos < c2.pos;
}
bool compareid(Car c1, Car c2)
{
	return c1.id < c2.id;
}

int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 0;i < n;i++)
	{
		cin >> cars[i].pos >> cars[i].direction;
		cars[i].id = i;
	}
	sort(cars, cars+n, comparepos);//����λ�ý�������
	while (t--)
	{
		int flag = 0;
		for (int i = 0;i < n;i++)
		{
			if (flag == 1)
			{
				flag--;
				continue;
			}
			else {
				if (cars[i + 1].pos - cars[i].pos == 1 && cars[i + 1].direction - cars[i].direction == -2)
				{
					cars[i].direction = -cars[i].direction;
					cars[i + 1].direction = -cars[i + 1].direction;
					flag = 1;
				}//�������Ϊһ�����������һ���ص�ԭ��λ�ã�������
				else {//�������ж����ŷ�����һ�������ж��Ƿ�����ײ
					cars[i].pos += cars[i].v * cars[i].direction;
					if (cars[i].state == 0)
						cars[i].state = -1;//��һ��֮���޸�֮ǰ�����Ķ�Ϊδ����
				}
			}
			
		}
		check_turn(n);
	}
	sort(cars, cars + n, compareid);
	for (int i = 0;i < n;i++)
	{
		cout << cars[i].pos << " ";
		if (cars[i].state == 0)
			cout << 0<<endl;
		else
			cout << cars[i].direction << endl;
	}
	return 0;
}