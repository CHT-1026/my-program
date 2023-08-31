#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
int ans1(int a, char b, int c);

int main()
{
	int ans = 0;
	char* sigarr;
	int* numarr;
	
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
	for (int a = 0; a < 4; a++)
	{
		
		for (int b = 0; b < 4; b++)
		{
			
				if (a != b)
				{
					for (int i = 0; i < 4; i++)
					{
						ans = ans1(numarr[a], sigarr[i], numarr[b]);
						for (int c = 0; c < 4; c++)
						{
							
								if (a != b && b != c && a != c)
								{
									for (int j = 0; j < 4; j++)
									{
										int ans2 = ans1(ans, sigarr[j], numarr[c]);
										for (int d = 0; d < 4; d++)
										{
												if (a != b && b != c && a != c && a != d && b != d && c != d)
												{
													for (int k = 0; k < 4; k++)
													{	
														
														if (ans1(ans2, sigarr[k], numarr[d]) == 24)
														{
															printf("% d % c % d % c % d % c % d\n", numarr[a], sigarr[i], numarr[b], sigarr[j], numarr[c], sigarr[k], numarr[d]);
														}
													}
												}
										}
									}
								}
						
						}
					}
				}
		}

	}

	free(sigarr);
	free(numarr);
	return 0;
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
