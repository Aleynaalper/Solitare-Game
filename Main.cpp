
#include <iostream>
#include <fstream>
#include <string>
#include "Methods.h"

using namespace std;



int main(int argc, const char *argv[]) {

	string text1=argv[1];
	string text2=argv[2];
	string text3=argv[3];

	Methods methods;
	methods.beginning(text1,text2,text3);
	return 0;
}
