#include<iostream>
using namespace std;

int atoi(char* a){
	if (a == NULL)
		return NULL;

	int flag = 1;

	if (*a == '+')
	{
		a++;
	}
	else if (*a == '-'){
		a++;
		flag = -1;
	}

	int i = 0;
	while(*a != '\0'){
		i = i * 10 + (*a) - '0';
		a++; 
	}

	return flag*i;
}

int main()
{
	char *a = "12314";
	cout<<atoi(a);
	
	return 0;
}
