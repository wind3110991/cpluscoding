#include<iostream>
using namespace std;

char* strcpy(char* dst, char *src){
	if (src == NULL || dst == NULL)
		return NULL;

	char* tmp = dst;

	while(*dst++ = *src++){}

	return tmp;
}

int main()
{
	char *a = "12314asdasa2asdasd12";
	char *ptr = a; 
	
	char b[4096] = {0};
	
	strcpy(b, a);

	cout<<b;
  
  return 0;
}
