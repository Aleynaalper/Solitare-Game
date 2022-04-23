
#ifndef READFROMFILE_H_
#define READFROMFILE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

class ReadFromFile {
public:
	ReadFromFile();

	virtual ~ReadFromFile();

	int deck(string deck[52]);

	int cmd();

	void define(string a,string b);
};

#endif /* READFROMFILE_H_ */
