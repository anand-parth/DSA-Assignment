#include<string.h>
#include<stdio.h>

void decode(char*);
void encode(char*);
char *reverse(char*);
int main()
{
	char input[255];
	scanf("%[^\n]s", input);
	// encode(input);
	decode(input);
}
void encode(char *input)
{
	int ct = 0;
	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i]!=' ')
		{
			if(((i+ct)%2)==0)
				input[i]+=3;
		}
		else
			ct++;
	}
	printf("%s\n", reverse(input));
}
void decode(char *str)
{
	char *input = reverse(str);
	int ct = 0;
	for(int i=0; input[i]!='\0'; i++)
	{
		if(input[i]!=' ')
		{
			if(((i+ct)%2)==0)
				input[i]-=3;
		}

		else
			ct++;
	}
	printf("%s\n", input);
}
char *reverse(char *input)
{
	int num = 0, len = 0 ;
	for(int i=0; input[i]!='\0' ; i++)
	{
		len++;
	}
	for(int i=0; i<=len ; i++)
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
	return input;	
}