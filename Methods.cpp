
#include "Methods.h"
#include "ReadFromFile.h"
#include "Control.h"
#include "Writing.h"

Control control;
Writing writingc;

string deck[52];
string stock[24];
int usingstock[3];
int stars=0;
int i=0;                              //It's for open from stock,
									  //I have defined it here so that it does not repeat itself when recalled
string index0[1];
string index1[2];
string index2[3];
string index3[4];
string index4[5];
string index5[6];
string index6[7];

string cindex0[19];                    //I defined six array to specify closed and opened cards
string cindex1[19];
string cindex2[19];
string cindex3[19];
string cindex4[19];
string cindex5[19];
string cindex6[19];

string upside[8];

Methods::Methods() {
}
Methods::~Methods() {
}

void Methods::beginning(string text1,string text2, string text3){
	ReadFromFile readfromfile;

	readfromfile.define(text1,text2);
	writingc.define(text3);

	readfromfile.deck(deck);


		index0[0]=deck[0];				//To fill the 0. column
		cindex0[0]=index0[0];

		for(int i=1;i<19;i++){
			cindex0[i]="   ";
		}

		index1[0]=deck[1];				//To fill the 1. column
		index1[1]=deck[7];

		cindex1[0]="@@@";
		cindex1[1]=index1[1];

		for(int i=2;i<19;i++){
			cindex1[i]="   ";
		}

		index2[0]=deck[2];				//To fill the 2. column
		index2[1]=deck[8];
		index2[2]=deck[13];

		for(int i=0;i<2;i++){
				cindex2[i]="@@@";
			}
		cindex2[2]=index2[2];

		for(int i=3;i<19;i++){
			cindex2[i]="   ";
		}

		index3[0]=deck[3];				//To fill the 3. column
		index3[1]=deck[9];
		index3[2]=deck[14];
		index3[3]=deck[18];

		for(int i=0;i<3;i++){
			cindex3[i]="@@@";
		}
		cindex3[3]=index3[3];

		for(int i=4;i<19;i++){
			cindex3[i]="   ";
		}
		index4[0]=deck[4];				//To fill the 4. column
		index4[1]=deck[10];
		index4[2]=deck[15];
		index4[3]=deck[19];
		index4[4]=deck[22];

		cindex4[4]=index4[4];

		for(int i=0;i<4;i++){
				cindex4[i]="@@@";
			}

		for(int i=5;i<19;i++){
			cindex4[i]="   ";
		}
		index5[0]=deck[5];				//To fill the 5. column
		index5[1]=deck[11];
		index5[2]=deck[16];
		index5[3]=deck[20];
		index5[4]=deck[23];
		index5[5]=deck[25];

		cindex5[5]=index5[5];


		for(int i=0;i<5;i++){
				cindex5[i]="@@@";
			}

		for(int i=6;i<19;i++){
			cindex5[i]="   ";
		}
		index6[0]=deck[6];				//To fill the 6. column
		index6[1]=deck[12];
		index6[2]=deck[17];
		index6[3]=deck[21];
		index6[4]=deck[24];
		index6[5]=deck[26];
		index6[6]=deck[27];

		cindex6[6]=index6[6];

		for(int i=0;i<6;i++){
				cindex6[i]="@@@";
			}
		for(int i=7;i<19;i++){
			cindex6[i]="   ";
		}

	//adding stock
	int j=28;
	for(int i=0; i<24; i++){
		stock[i]=deck[j];
		j++;
	}

	upside[0]="@@@";
	for (int i=1;i<8;i++){
		upside[i]="___";

	}
	writing();
	readfromfile.cmd();
}

void Methods::openfromstock() {
    string upside1=upside[1];      		//It's used for opened stock elements
    string upside2=upside[2];
    string upside3=upside[3];

    int lastelement;
    int j = 1;
    int k = 0;
    for (int m = 23; m >= 0; m--) {
        if (stock[m] == "") {
            continue;
        } else {
            lastelement = m;
            break;
        }
    }
    if(i>=lastelement+1) {
        upside[0] = "@@@";
        upside[1]="___";
        upside[2]="___";
        upside[3]="___";
        j=5;
        i=0;
    }
    while (j < 4) {
        if (stock[i] == "") {
            i++;
            continue;
        }
        usingstock[k] = i;
        upside[j] = stock[i++];
        k++;
        j++;

    if (i >= lastelement+1) {
        upside[0] = "___";
        break;
    	}
    }
   if(upside1==upside[1]) {
       upside[1]="___";
   	   }
    if(upside2==upside[2]) {
        upside[2] = "___";
    	}
    if(upside3==upside[3]) {
        upside[3]="___";
    	}
        writing();
	}

void Methods::open(int number){
	if(number==0){
		writingc.writefile("Invalid Move!\n\n");
		}
	else if(number==1){
		if(cindex1[1]=="   " && cindex1[0]=="@@@"){
			cindex1[0]=index1[0];
			}
		else{
			writingc.writefile("Invalid Move!\n\n");
			}

	}
	else if(number==2){
		for(int i=0;i<2;i++){
			if(cindex2[i+1]=="   " && cindex2[i]=="@@@"){
				cindex2[i]=index2[i];
                break;
			}
			else if(i==1){
				writingc.writefile("Invalid Move!\n\n");
				}
			}
		}
	else if(number==3){
			for(int i=0;i<3;i++){
				if(cindex3[i+1]=="   " && cindex3[i]=="@@@"){
					cindex3[i]=index3[i];
                    break;
				}
				else if(i==2){
					writingc.writefile("Invalid Move!\n\n");
					}
				}
			}
	else if(number==4){
			for(int i=0;i<4;i++){
				if(cindex4[i+1]=="   " && cindex4[i]=="@@@"){
					cindex4[i]=index4[i];
                    break;
				}
				else if(i==3){
					writingc.writefile("Invalid Move!\n\n");
					}
				}
			}
	else if(number==5){
			for(int i=0;i<5;i++){
				if(cindex5[i+1]=="   " && cindex5[i]=="@@@"){
					cindex5[i]=index5[i];
                    break;
				}
				else if(i==4){
					writingc.writefile("Invalid Move!\n\n");
					}
				}
			}
	else if(number==6){
			for(int i=0;i<6;i++){
				if(cindex6[i+1]=="   " && cindex6[i]=="@@@"){
					cindex6[i]=index6[i];
                    break;
				}
				else if(i==5){
					writingc.writefile("Invalid Move!\n\n");
					}
				}
			}
	writing();
}

void Methods::movewaste(int number){
    string lastcard="___";
	string variable;
	for(int i=3;i>0;i--){
		if(upside[i]=="___"){
			continue;
		}
		else{
			variable=upside[i];
			bool x=pilecontrol(variable,number);

			if(x==true){
                if(i==1) {
                    for(int j = 0 ; j<24 ; j++) {
                        if(stock[j]==variable) {
                            break;
                        }
                        else if(!(stock[j]=="")) {
                            lastcard=stock[j];
                        }
                    }
                }
				int index=usingstock[i-1];
				stock[index]="";
				upside[i]="___";
				break;
			}
			else{
				writingc.writefile("Invalid Move!\n\n");
				break;
			}
		}
	}
	if(upside[1]=="___") {
	    upside[1]=lastcard;
	}
	writing();
}

void Methods::movetofoundationwaste() {
    string lastcard="___";
    string variable;
    for (int i = 3; i > 0; i--) {
        if (upside[i] == "___") {
            continue;
        } else {
            variable = upside[i];
            bool x = foundationcontrol(variable);

            if (x == true) {
                if(i==1) {
                    for(int j = 0 ; j<24 ; j++) {
                        if(stock[j]==variable) {
                            break;
                        }
                        else if(!(stock[j]=="")) {
                            lastcard=stock[j];
                        }
                    }
                }
                int index = usingstock[i - 1];
                stock[index] = "";

                upside[i] = "___";
                break;
            	}
            	else {
            	writingc.writefile("Invalid Move!\n\n");
                break;
            }
        }
    }
    if (upside[1] == "___") {
        upside[1]=lastcard;
}
		writing();
	}

void Methods::movefoundation(int number1,int number2){
	string variable;
	string newvariable;
	string type;
	int index;

	if(number1==0){
		index=4;
		}
	else if(number1==1){
		index=5;
		}
	else if(number1==2){
		index=6;
		}
	else if(number1==3){
		index=7;
		}

	variable=upside[index];

	if(variable.at(0)=='H'){
			type="H";
	}
	else if(variable.at(0)=='D'){
		type="D";
	}
	else if(variable.at(0)=='S'){
		type="S";
	}
	else if(variable.at(0)=='C'){
		type="C";
	}
	else{
		writingc.writefile("Invalid Move!\n\n");
		writing();
		return;
	}

	variable.erase(0,1);
	int result=stoi(variable);

	bool x=pilecontrol(variable,number2);

			if(x==true){
				if(result==1){
					upside[index]="___"; }
				else{
					result--;
					newvariable=to_string(result);
					if(result<10){
						upside[index]=type+"0"+newvariable;
					}
					else{
						upside[index]=type+newvariable;
					}
				}
			}
			else{
				writingc.writefile("Invalid Move!\n\n");
				writing();
				return;
			}
	writing();
}

void Methods::movepile(int number1,int number2,int number3){
	string variable;
		int i=18;
		if(number1==0){
			while(i>=0){
				if(cindex0[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex0[i]=="   "){
					i--;
					continue;}
				else {
					if(number2>0){
						for(int j=number2;j>0;j--){
							variable=cindex0[i-j];
							if(variable=="@@@"){
								writingc.writefile("Invalid Move!\n\n");
								writing();
								return;
								}
							else if(variable=="   "){
								writingc.writefile("Invalid Move!\n\n");
								writing();
								return;
							}
							bool x=pilecontrol(variable,number3);

							if(x==true){
								cindex0[i-j]="   ";
								continue;
							}
							else{
								writingc.writefile("Invalid Move!\n\n");
								writing();
								return;
							}
						}
					}
					variable=cindex0[i];
					if(variable=="@@@"){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					bool x=pilecontrol(variable,number3);

					if(x==true){
						cindex0[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}
		if(number1==1){
				while(i>=0){
					if(cindex1[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex1[i]=="   "){
						i--;
						continue;}
					else {
						if(number2>0){
							for(int j=number2;j>0;j--){

								variable=cindex1[i-j];
								if(variable=="@@@"){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
									}
								else if(variable=="   "){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
								bool x=pilecontrol(variable,number3);

								if(x==true){
									cindex1[i-j]="   ";
									continue;
								}
								else{
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
							}
						}
						variable=cindex1[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex1[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
					}
				}
			}
		if(number1==2){
				while(i>=0){
					if(cindex2[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex2[i]=="   "){
						i--;
						continue;}
					else {
						if(number2>0){
							for(int j=number2;j>0;j--){

								variable=cindex2[i-j];
								if(variable=="@@@"){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
									}
								else if(variable=="   "){
									writingc.writefile("Invalid Move!\n\n");   //boþluk koþuluna da bak
									writing();
									return;
								}
								bool x=pilecontrol(variable,number3);

								if(x==true){
									cindex2[i-j]="   ";
									continue;
								}
								else{
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
							}
						}
						variable=cindex2[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex2[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
					}
				}
			}

		if(number1==3){
				while(i>=0){
					if(cindex3[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex3[i]=="   "){
						i--;
						continue;}
					else {
						if(number2>0){
							for(int j=number2;j>0;j--){

								variable=cindex3[i-j];
								if(variable=="@@@"){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
									}
								else if(variable=="   "){
									writingc.writefile("Invalid Move!\n\n");   //boþluk koþuluna da bak
									writing();
									return;
									}
								bool x=pilecontrol(variable,number3);

								if(x==true){
									cindex3[i-j]="   ";
									continue;
								}
								else{
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
							}
						}
						variable=cindex3[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex3[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
					}
				}
			}

		if(number1==4){
				while(i>=0){
					if(cindex4[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex4[i]=="   "){
						i--;
						continue;}
					else {
					if(number2>0){
						for(int j=number2;j>0;j--){

							variable=cindex4[i-j];
							if(variable=="@@@"){
								writingc.writefile("Invalid Move!\n\n");
								writing();
								return;
								}
							else if(variable=="   "){
								writingc.writefile("Invalid Move!\n\n");   //boþluk koþuluna da bak
								writing();
								return;
							}
							bool x=pilecontrol(variable,number3);

							if(x==true){
								cindex4[i-j]="   ";
								continue;
							}
							else{
								writingc.writefile("Invalid Move!\n\n");
								writing();
								return;
							}
						}
					}
						variable=cindex4[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex4[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
					}
				}
			}

		if(number1==5){
				while(i>=0){
					if(cindex5[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex5[i]=="   "){
						i--;
						continue;}
					else {
						if(number2>0){
							for(int j=number2;j>0;j--){

								variable=cindex5[i-j];
								if(variable=="@@@"){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
									}
								else if(variable=="   "){
									writingc.writefile("Invalid Move!\n\n");   //boþluk koþuluna da bak
									writing();
									return;
								}
								bool x=pilecontrol(variable,number3);

								if(x==true){
									cindex5[i-j]="   ";
									continue;
								}
								else{
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
							}
						}
						variable=cindex5[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex5[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
					}
				}
			}

		if(number1==6){
				while(i>=0){
					if(cindex6[0]=="   "){
						writingc.writefile("Invalid Move!\n\n");
						break;
						}
					else if(cindex6[i]=="   "){
						i--;
						continue;}
					else {
						if(number2>0){
							for(int j=number2;j>0;j--){

								variable=cindex6[i-j];
								if(variable=="@@@"){
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
								else if(variable=="   "){
									writingc.writefile("Invalid Move!\n\n");   //boþluk koþuluna da bak
									writing();
									return;
								}
								bool x=pilecontrol(variable,number3);

								if(x==true){
									cindex6[i-j]="   ";
									continue;
								}
								else{
									writingc.writefile("Invalid Move!\n\n");
									writing();
									return;
								}
							}
						}
						variable=cindex6[i];
						if(variable=="@@@"){
							writingc.writefile("Invalid Move!\n\n");
							break;
							}
						else{
						bool x=pilecontrol(variable,number3);

						if(x==true){
							cindex6[i]="   ";
							break;
						}
						else{
							writingc.writefile("Invalid Move!\n\n");
							break;
						}
						}
					}
				}
			}
		writing();
}


bool Methods::pilecontrol(string variable,int number3){
		string type;
		string type1;
		string type2;
		string gradervariable;
		if(variable.at(0)=='H' || variable.at(0)=='D'  ){

			char t=variable.at(0);
			string btype(1,t);
			type=btype;
			type1="C";
			type2="S";
		}

		else if(variable.at(0)=='S'|| variable.at(0)=='C'){
			char t=variable.at(0);
			string btype(1,t);
			type=btype;
			type1="H";
			type2="D";
		}

		variable.erase(0,1);
		int result=stoi(variable);

			int i=18;
			if(number3==0){
				while(i>=0){
					if(cindex0[i]=="   "){
						if(cindex0[0]=="   " && result==13){
							cindex0[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex0[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex0[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex0[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==1){
				while(i>=0){
					if(cindex1[i]=="   "){
						if(cindex1[0]=="   " && result==13){
							cindex1[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex1[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex1[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex1[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==2){
				while(i>=0){
					if(cindex2[i]=="   "){
						if(cindex2[0]=="   " && result==13){
							cindex2[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex2[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex2[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex2[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==3){
				while(i>=0){
					if(cindex3[i]=="   "){
						if(cindex3[0]=="   " && result==13){
							cindex3[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex3[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex3[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex3[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==4){
				while(i>=0){
					if(cindex4[i]=="   "){
						if(cindex4[0]=="   " && result==13){
							cindex4[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex4[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex4[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex4[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==5){
				while(i>=0){
					if(cindex5[i]=="   "){
						if(cindex5[0]=="   " && result==13){
							cindex5[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex5[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex5[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex5[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}

			else if(number3==6){
				while(i>=0){
					if(cindex6[i]=="   "){
						if(cindex6[0]=="   " && result==13){
							cindex6[0]=type+variable;
							return true;
						}
						i--;
						continue;}
					else if(cindex6[i]=="@@@"){
						return false;
						}
					else {
						gradervariable=cindex6[i];
						char g=gradervariable.at(0);
						string gradertype(1,g);

						gradervariable.erase(0,1);
						int graderresult=stoi(gradervariable);

						if(graderresult==result+1 && (gradertype==type1 || gradertype==type2)){
							cindex6[i+1]=type+variable;
							return true;
						}
						else{
							return false;
							}
						}
					}
				}
			return false;
			}

void Methods::movetofoundationpile(int number){
	string variable;
	int i=18;
	if(number==0){
		while(i>=0){
			if(cindex0[0]=="   "){
				writingc.writefile("Invalid Move!\n\n");
				break;
				}
			else if(cindex0[i]=="   "){
				i--;
				continue;}
			else {
				variable=cindex0[i];
				bool x=foundationcontrol(variable);

				if(x==true){
					cindex0[i]="   ";
					break;
				}
				else{
					writingc.writefile("Invalid Move!\n\n");
					break;
				}
			}
		}
	}
	if(number==1){
			while(i>=0){
				if(cindex1[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex1[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex1[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex1[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}
	if(number==2){
			while(i>=0){
				if(cindex2[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex2[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex2[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex2[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}

	if(number==3){
			while(i>=0){
				if(cindex3[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex3[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex3[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex3[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}

	if(number==4){
			while(i>=0){
				if(cindex4[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex4[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex4[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex4[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}

	if(number==5){
			while(i>=0){
				if(cindex5[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex5[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex5[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex5[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}

	if(number==6){
			while(i>=0){
				if(cindex6[0]=="   "){
					writingc.writefile("Invalid Move!\n\n");
					break;
					}
				else if(cindex6[i]=="   "){
					i--;
					continue;}
				else {
					variable=cindex6[i];
					bool x=foundationcontrol(variable);

					if(x==true){
						cindex6[i]="   ";
						break;
					}
					else{
						writingc.writefile("Invalid Move!\n\n");
						break;
					}
				}
			}
		}
	writing();
}

bool Methods::foundationcontrol(string variable){
	int i;
	string type;
	if(variable.at(0)=='H'){
		i=4;
		type="H";
	}
	else if(variable.at(0)=='D'){
		i=5;
		type="D";
	}
	else if(variable.at(0)=='S'){
		i=6;
		type="S";
	}
	else if(variable.at(0)=='C'){
		i=7;
		type="C";
	}

	variable.erase(0,1);
	int result=stoi(variable);

	if(upside[i]=="___"){
		if(result==1){
			upside[i]=type + variable;
			return true;
		}
		else{
			return false;
			}
		}
	else {
		string foundation1=upside[i];
		foundation1.erase(0,1);
		int foundation2=stoi(foundation1);

		if(foundation2+1 == result){
			upside[i]=type + variable;
			return true;
		}
		else{
			return false;
			}
		}
	}

 void Methods::writing(){
	 if(stars!=0){
		writingc.writefile("****************************************\n");
	 }
	 writingc.writefile("\n"+upside[0]+" "+upside[1]+" "+upside[2]+" "+upside[3]+"         "+upside[4]+" "+upside[5]+" "+upside[6]+" "+upside[7]+"\n\n");

	for(int i=18;i>=0;i--){
		if(cindex0[i]=="   " && cindex1[i]=="   " && cindex2[i]=="   " && cindex3[i]=="   " && cindex4[i]=="   " && cindex5[i]=="   " && cindex6[i]=="   "){
			continue;
		}
		else{
			for(int j=0;j<=i;j++){
				writingc.writefile(cindex0[j]+"   "+cindex1[j]+"   "+cindex2[j]+"   "+cindex3[j]+"   "+cindex4[j]+"   "+cindex5[j]+"   "+cindex6[j]+"\n");
			}
			writingc.writefile("\n");
			break;
		}
	}
	stars++;
	if(cindex0[0]=="   " && cindex1[0]=="   " && cindex2[0]=="   " && cindex3[0]=="   " && cindex4[0]=="   " && cindex5[0]=="   " && cindex6[0]=="   "){
		writingc.writefile("\n\n****************************************\n\n");
		writingc.writefile("You Win!\n\n");
		writingc.writefile("Game Over!\n");
		}
 }
