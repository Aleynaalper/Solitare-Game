#include "Control.h"
#include "Methods.h"
#include "Writing.h"

Control::Control() {
}

Control::~Control() {
}

void Control::controlling(string controlarray[5]){

    Methods methods;
    Writing writing;

    if(controlarray[0]=="exit"){
    	writing.writefile("exit\n\n");
    	writing.writefile("****************************************\n\n");
        writing.writefile("Game Over!\n");
    }

    else if(controlarray[1]=="pile"){

    	writing.writefile("move pile "+controlarray[2]+" "+controlarray[3]+" "+controlarray[4]+"\n\n");

        int number1=stoi(controlarray[2]);
        int number2=stoi(controlarray[3]);
        int number3=stoi(controlarray[4]);
        methods.movepile(number1, number2, number3);
    }

    else if(controlarray[1]=="waste"){
    	writing.writefile("move waste "+controlarray[2]+"\n\n");

        int number=stoi(controlarray[2]);
        methods.movewaste(number);
    }

    else if(controlarray[1]=="from"){
    	writing.writefile("open from stock\n\n");
        methods.openfromstock();
    }

    else if(controlarray[3]=="pile"){
    	writing.writefile("move to foundation pile "+controlarray[4]+"\n\n");

        int number=stoi(controlarray[4]);
        methods.movetofoundationpile(number);
    }

    else if(controlarray[3]=="waste"){
    	writing.writefile("move to foundation waste\n\n");
        methods.movetofoundationwaste();
    }

    else if(controlarray[0]=="open"){
    	writing.writefile("open "+controlarray[1]+"\n\n");

        int number=stoi(controlarray[1]);
        methods.open(number);
    }

    else if(controlarray[1]=="foundation"){
    	writing.writefile("move foundation "+controlarray[2]+" "+controlarray[3]+"\n\n");

    	int number1=stoi(controlarray[2]);
    	int number2=stoi(controlarray[3]);
    	methods.movefoundation(number1, number2);
    }

}


