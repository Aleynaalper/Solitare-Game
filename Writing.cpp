#include "Writing.h"

Writing::Writing() {
}
Writing::~Writing() {
}
string text3;

void Writing::define(string c){
	text3=c;

}
void Writing::writefile(string line){

	ofstream outfile;

	outfile.open(text3, ios_base::app);		//it crates new text file that name is output.txt
	outfile << line;								//it prints each element it takes as a parameter to text file

	if(line=="Game Over!\n"){
		outfile.close();
	   }
	}






