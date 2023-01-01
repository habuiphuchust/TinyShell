#include <string>
#include "simplefunction.h"
#include <cstring>
#include <sstream>
#include "complexfunctions.h"
#include <fstream>

void runBat (const char* link);

using namespace std;

string path = "application/";
bool parse(string instruction) {
	// phan tich dong lenh
	vector<string> argv;
	stringstream sinstruction;
	sinstruction.str(instruction);
	while (!sinstruction.eof()) {
		string in;
		sinstruction >> in;
		argv.push_back(in);
	}
	int size = argv.size();
	
	if (argv[0] == "help") {
		if (size != 1) return false;
		cout << "date: xem ngay"<<endl<<
		"time:  xem thoi gian"<<endl<<
		"list: xem ds tien trinh"<<endl<<
		"create [name] [f|b]:  tao tien trinh [name]"<<endl<<
		"f: foreground, b: background, file *.bat chi chay foreground"<<endl<<
		"stop [Id]:  tam dung tien trinh [Id]"<<endl<<
		"resume [Id]:  tiep tuc tien trinh [Id]"<<endl<<
		"kill [Id]: ket thuc tien trinh [Id]"<<endl<<
		"path:  xem bien moi truong"<<endl<<
		"addpath [newpath]: sua bien moi truong"<<endl;
		return true;
	}
	
	if (argv[0] == "list") {     //ok
		if (size = 1) {
			viewList();
			return true;
		}
	}
	
	if (argv[0] == "kill") { //ok
		if (size == 2) {
			killProcess(argv[1]);
			return true;
		} else {
			cout << "nhap sai ID tien trinh"<< endl;
			return true;
		}
	}
	
	if (argv[0] == "stop") {
		if (size == 2) {
			Stop(argv[1]);
			return true;
		} else {
			cout << "nhap sai ID tien trinh"<< endl;
			return true;
		}
	}
	
	if (argv[0] == "resume") {
		if (size == 2) {
			Resume(argv[1]);
			return true;
		} else {
			cout << "nhap sai ID tien trinh"<< endl;
			return true;
		}
	}
	
	if (argv[0] == "path") {//ok
		if(size == 1) {
			cout << "path = "<< path <<endl;
			return true;
		} else return false;
	}
	
	if (argv[0] == "addpath") { //ok
		if (size == 2) {
			addPath(path, argv[1]);
			return true;
		} else{
			cout << "nhap sai bien moi truong" << endl;
			return true;
		} 
		return false;
	}
	
	if (argv[0] == "create") {     //ok
		if (size == 1) {
			cout << "nhap thieu ten tien trinh" << endl;
			return true;
		}
		string npath = path + argv[1];
		int index = npath.size();
        const char* link = npath.c_str();
        bool bat = false;
        if (npath[index-4] == '.' && npath[index-3] == 'b' && npath[index-2] == 'a' && npath[index-1] == 't')
        	bat = true;        
		if (size == 2) {
			if (bat) {
				runBat(link);
				return true;
			} else {
				createForeGround(link);
				return true;	
			}	
		}
		if (size == 3) {
			if (argv.at(2) == "f") {
				if (bat) {
				runBat(link);
				return true;
				} 
				createForeGround(link);
				return true;
			}
			if (argv.at(2) == "b") {
				if (bat) {
				runBat(link);
				return true;
				} 
				createBackGround(link);
             	return true;
			}
		}
		return false;
		
	}
	
	if (argv[0] == "date") {  //ok
		if(size == 1) {
			getDate();
			return true;			
		} else return false;
	}
	
	if (argv[0] == "time") {//ok
		if(size == 1) {
			getTime();
			return true;
		} else return false;
		
	}
	
	if (argv[0] == "dir") {
		cout << "chua update cau lenh" << endl;
		return true;
	}
	if (argv[0] == "exit") {
		
	}

	return false;
}



void runBat (const char* link){

    // Khai báo vector để lưu các dòng đọc được
    vector<string> lines;
    string line;

    //Mở file bằng ifstream
    ifstream input_file(link);
    //Kiểm tra file đã mở thành công chưa
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << link << "'" << endl;
        return;
    }

    //Đọc từng dòng trong
    while (getline(input_file, line)){
        lines.push_back(line);//Lưu từng dòng như một phần tử vào vector lines.
    }

    //phan tich tung dong
    for (const auto &i : lines) {
    	cout<<i<<endl;
        parse(i);
	}
    	
    input_file.close();
    return ;
}
