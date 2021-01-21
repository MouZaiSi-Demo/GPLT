#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
	int N, row = 0;
	char c;
	cin >> N >> c;
	for (int i = 0;; i++)
	{
		if (2 * i * i + 4 * i + 1 > N)//等差数列求和*2+1
		{
			row = i - 1;
			break;
		}
	}

		for (int i = row ;i >0; i--)
		{
			for (int k = row - i; k > 0; k--)
			{
				cout << ' ';
			}
			for (int j = 2 * i +1;j>0;j--)
			{
				cout << c;
			}
			cout << endl;
		}

		for (int i = 0; i < row + 1; i++)
		{
			for (int k = 0;k < row - i;k++)
			{
				cout << ' ';
			}
			for (int j = 0; j < 2*i +1; j++)
			{
				cout << c;
			}
			cout << endl;
		}
		cout << N - (2 * row * row + 4 * row + 1);

		return 0;
}



	
