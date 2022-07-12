#pragma once

#include<iostream>

using std::istream; 
using std::ostream;


class string {

	char* str;

	unsigned int length;

	

	/// <summary>
	/// This function will copy the value of the given string into the current string
	/// </summary>
	/// <param name="source"></param>
	void stringCopy(char* source);
	
	friend istream& operator>> (istream& is, string& obj)
	{
		char* buff = new char[1000];
		memset(&buff[0], 0, sizeof(buff));
		is >> buff;
		obj = string{ buff };
		delete[] buff;
		return is;
	}
	friend ostream& operator<<(ostream& os, const string& obj)
	{
		os << obj.str;
		return os;
	}
	string& operator= (const string& rhs) {

		// if the assignment is the same variable
		if (this == &rhs)
			return *this;
		// removing the old value
		delete[] str;
		// giving the new value;
		str = new char[rhs.length + 1];
		stringCopy(rhs.str);
		return *this;

	}
	string& operator= (const char* val) {

		delete[] str;
		str = new char[8];
		str = (char*)"anirudh";
		return *this;
	}
	
public:

	// defaut constructor
	string();

	// Constructor with predefined value
	string(char* val);
	string(const char* val);
	// Copy constructor
	string(const string& source);
	// Move constructor
	string(string&& source);

	~string() { delete[] str; }

	
	
	unsigned int strLength(const char* strL) {
		
		unsigned int len = 0;
		while (*strL !='\0')
		{
			len++;
			strL++;
		}
		return len;
		
	}

	void stringCpy(string source);
	void stringConcat(string dest, string source);
	
	
	

};
