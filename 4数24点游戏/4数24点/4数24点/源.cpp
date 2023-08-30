#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
int ans1(int a, char b, int c);

int main()
{
	char* sigarr;
	int* numarr;
	int ans;
	numarr = (int*)malloc(sizeof(int)*4);
	sigarr = (char*)malloc(sizeof(char) * 4);
	assert(sigarr);
	sigarr[0] = '+';
	sigarr[1] = '-';
	sigarr[2] = '*';
	sigarr[3] = '/';
	assert(numarr);
	printf("请输入4个数字（不大于10）（逗号隔开）\n");
	scanf("%d,%d,%d,%d",&numarr[0], &numarr[1], &numarr[2], &numarr[3]);
	for (int i = 0; i < 4; i++)
	{
		ans = ans1(numarr[0], sigarr[i], numarr[1]);
		for (int j = 0; j < 4; j++)
		{
			ans= ans1(ans, sigarr[j], numarr[2]);
			for (int k = 0; k < 4; k++)
			{
				ans = ans1(ans, sigarr[k], numarr[3]);
				if (ans == 24)
				{
					printf("%d %c %d %c %d %c %d\n", numarr[0], sigarr[i], numarr[1], sigarr[j], numarr[2], sigarr[k], numarr[3]);
				}
			}
		}

	}

	free(sigarr);
	free(numarr);
	return 0;
}

void swap(int* a, int* b)
{
	int* temp=NULL;
	temp = a;
	a = b;
	b = temp;
}

int ans1(int a, char b, int c)
{
	if (b == '+')
	{
		return a + c;
	}
	else if (b == '-')
	{
		return a - c;
	}
	else if (b == '*')
	{
		return a * c;
	}
	else if (b == '/'&&c!=0)
	{
		return a / c;
	}
}
