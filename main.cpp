#include <iostream>
#include <string>
#include <vector>
#include"parseinstruction.h"
#include <windows.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) {
	cout << "Ha Bui Phuc 20204773 - gv Pham Dang Hai - project1 TinyShell"<< endl;
	cout << "nhap help de xem huong dan su dung" << endl;
    while(1) {
    	cout << "TinyShell $";
	    string input;
	    fflush(stdin);
	    getline(cin, input);
	    if (input == "exit") {
	    	break;
		}
		if(!parse(input)) cout << "nhap sai cau lenh " << endl;
		sleep(0.5);
		
	}
	cout << "TinyShell ket thuc" << endl;
	getch();
	return 0;
}