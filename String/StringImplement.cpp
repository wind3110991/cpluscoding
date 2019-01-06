/*****************************************************
        String Implement
*****************************************************/
 
#include <iostream>
#include <string.h>
#include "String.h"
 
using namespace std;
 
String::String()
{
	str_ = new char['\0'];
	cout << "default construct String!" << endl;
}
 
String::String(char *str)
{
	cout << "construct String!" << endl;
 
	int len = strlen(str) + 1;
	str_ = new char[len];
	memset(str_, 0, len);
	strcpy(str_, str)
}
 
String::String(const String& other)
{
	int len = strlen(other.str_) + 1;
	str_ = new char[len];
	memset(str_, 0, len);
	strcpy(str_, other.str_);
}
 
String& String::operator=(const String& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	int len = strlen(other.str_) + 1;
	delete [] str_;
	str_ = new char[len];
	memset(str_, 0, len);
	strcpy(str_, other.str_);
 
	return *this;
}
 
String& String::operator=(char *str)
{
	delete [] str_;
	int len = strlen(str) + 1;
	str_ = new char[len];
	memset(str_, 0, len);
	strcpy(str_, str);
 
	return *this;
}
 
char& String::operator[](unsigned int index)
{
	//return str_[index];
	return const_cast<char&>(static_cast<const String&>(*this)[index]);
}
 
const char& String::operator[](unsigned int index) const //结尾const表示不能在该函数内修改类成员
{
	return str_[index];
}
 
String operator+(const String& s1, const String& s2)
{
#if 0
	int len = strlen(s1.str_) + strlen(s2.str_) + 1;
	char *newptr = new char[len];
	memset(newptr, 0, len);
	strcpy(newptr, s1.str_);
	strcat(newptr, s2.str_);
	String tmp(newptr);
#endif
 
	String tmp(s1);
 
	tmp += s2;
 
	return tmp;
}
 
String& String::operator+=(const String& s)
{
	int len = strlen(s.str_) + strlen(str_) + 1;
 
	char *newptr = new char[len];
	memset(newptr, 0, len);
	strcpy(newptr, str_);
	strcat(newptr, s.str_);
	String tmp(newptr);
	
	delete [] str_;
	str_ = new char[len];
	strcpy(str_, newptr);
 
	return *this;
}
 
ostream& operator<<(ostream& out, const String& s)
{
	out << s.str_;
	return out;
}
 
istream& operator>>(istream& in, String& s)
{
	char buffer[4096];
 
	in >> buffer;
	s.str_ = buffer;
 
	return in;
}
 
String::~String()
{
	cout << "destroy String!" << endl;
}
 
void String::Display()
{
	cout << "str = " << str_ << endl;
}
