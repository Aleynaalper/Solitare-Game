#include "ReadFromFile.h"
#include "Control.h"

ReadFromFile::ReadFromFile() {
}
ReadFromFile::~ReadFromFile() {
}
string text1;
string text2;

void ReadFromFile::define(string a,string b){
	text1=a;
	text2=b;
}

int ReadFromFile::deck(string deck[52]){
	int i=51;

		ifstream file(text1);
			if(!file){
				cerr <<"File couldn't find" << endl;
				exit(1);
			}
			while(file){
				string name;
				getline(file,name);
				deck[i]=name;					//it sends every elements from deck.txt to deck array
				i--;

				if(i == -1)
					break;
			}
			return 0;
}

int ReadFromFile::cmd(){
	ifstream file(text2);
			if(!file){
				cerr <<"File couldn't find" << endl;
				exit(1);
				}
			while(file){
				string controlarray[5];
				string name;

				getline(file,name);

				int l=name.length();

				char commandarray[l + 1];   //to using strtok , I converted string to char array
				char split[]=" ";
				strcpy(commandarray, name.c_str());
				char *token=strtok(commandarray,split);

				int i=0;
				while(token){
					controlarray[i]=token;      //to find which command, I define every element into the array after separating it with spaces
					token = strtok(NULL,split);
					i++;
					}

				Control control;
				control.controlling(controlarray);
			}
			return 0;
}

