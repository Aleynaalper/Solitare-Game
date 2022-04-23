
#ifndef METHODS_H_
#define METHODS_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class Methods {

public:
	Methods();
	virtual ~Methods();
	void beginning(string text1,string text2, string text3);
	void writing();

	void openfromstock();

	void movetofoundationpile(int number);		//It uses foundation control method in this method
	bool foundationcontrol(string variable);

	void open(int number);

	void movepile(int number1, int number2, int number3); ////It uses pile control method in this method
	bool pilecontrol(string variable,int number3);

	void movewaste(int number);						//It uses pile control method in this method

	void movetofoundationwaste();				    //It uses foundation control method in this method

	void movefoundation(int number1,int number2);  //It uses pile control method in this method

};

#endif /* METHODS_H_ */
