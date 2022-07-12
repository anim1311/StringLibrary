#include "myString.h"

/// <summary>
/// This will create a new string class with a null char
/// </summary>
string::string() {
	
	this->length = 0;
	this->str = new char[1];
	this->str[0] = '\0';
}

/// <summary>
/// this will create a string class with the value given by the user
/// </summary>
/// <param name="val"></param>
string::string(char* val) {
	
	this->length = 0;
	if (val == nullptr) {
		
		str = new char[1];
		str[0] = '\0';
	}
	else {

		this->length = strLength(val);
		str = new char[this->length +1];
		str[this->length] = '\0';

	}
}
string::string(const char* val) {


	if (val == nullptr) {
		
		this->length= 0;
		str = new char[1];
		str[0] = '\0';
	}
	else {

		this->length = strLength((const char*)val);
		this->stringCopy((char*)val);

	}
}

/// <summary>
/// This will copy an already created string class into a new string class
/// </summary>
/// <param name="source"></param>
string::string(const string& source){

	str = new char[source.length+1];
	stringCopy(source.str);
}

string::string(string&& source)
{

	str = source.str;
	source.str = nullptr;
}


void string::stringCopy(char* source) {

	delete[] str;

	int length = strLength(source);
	str = new char[length+ 1];

	for (int i = 0; *(source+i)!='\0'; i++)
		*(str + i) = *(source + i);
	str[length] = '\0';
}

/// <summary>
/// this function is going to copy the passed string into the current string
/// </summary>
/// <param name="source"></param>
void string::stringCpy(string source) {
	this->stringCopy(source.str);
}