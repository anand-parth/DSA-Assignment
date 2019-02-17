#include<string.h>
#include<stdio.h>

int main()
{
	char input[255];
	int ct=0;
	scanf("%[^\n]s", input);
	int val = 0;
	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i]!=' ')
		{
			if(((i+ct)%2)==0)
				input[i]+=3;
		}
		else
			ct++;
		val = i;
	}
	// int l =sizeof(input)/sizeof(input[0]);
	for(int i=0; input[i]!='\0'; i++)
	{
		printf("%c", input[i]);
	}
	printf("\n");
	int num = 0;
	for(int i=0; i<=val+1; i++)
	{
		if(input[i]==' ' || input[i]=='\0')
		{	
			for(int j=num;j<((num+i)/2);j++)
			{	
				char tmp = input[j];
				input[j] = input[i+num-1-j];
				input[i+num-1-j] = tmp;
			}
			num = i+1;
		}
	}
		for(int i=0; input[i]!='\0'; i++)
	{
		printf("%c", input[i]);
	}
	return 0;
}