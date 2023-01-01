#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct APPINFO {
	PROCESS_INFORMATION info;
	string name;
	short int status = 1;
	
};
vector<APPINFO> backapp;
    
void createBackGround (const char* link) {
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
 
    if( !CreateProcess(link, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi ) ) 
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return  ;
    }
    backapp.push_back({pi, link, true});
}

void viewList() {
	cout << "ID---TenTienTrinh---TrangThai"<<endl;
	if (backapp.size() == 0) {
		cout << "KHONG CO TIEN TRINH NAO DANG CHAY" << endl;
		return;
	}
	for(auto itr = backapp.end() - 1; itr >= backapp.begin(); --itr) {
 		// Xử lý
		DWORD exitCode = 0;
	    GetExitCodeProcess((*itr).info.hProcess, &exitCode);

		if (exitCode == STILL_ACTIVE)
		{
			cout << (*itr).info.dwProcessId<< "---"<<(*itr).name<< "---";
  	 		if ((*itr).status ) cout << "HoatDong"<<endl;
  	 		else cout << "TamNgung"<<endl;
		} else {
			CloseHandle( (*itr).info.hProcess );
			CloseHandle( (*itr).info.hThread );
			backapp.erase(itr);
		}
	}
}

void killProcess(string s) {
	if (backapp.size() == 0) {
		cout << "khong co tien trinh  nao dang chay" << endl;
		return;
	}
	for(auto itr = backapp.end() - 1; itr >= backapp.begin(); --itr) {
 		// Xử lý
 		const char* d = s.c_str();
		DWORD Id = atoi(d);

		if ( (*itr).info.dwProcessId == Id)
		{
			TerminateProcess((*itr).info.hProcess, 0);
			CloseHandle( (*itr).info.hProcess );
			CloseHandle( (*itr).info.hThread );
			cout << " da tat tien trinh: "<< (*itr).info.dwProcessId << "---" << (*itr).name << endl;
			backapp.erase(itr);
			return;
		}
	}
	cout << "khong tim duoc tien trinh" << endl;
	
}

void Stop (string s) {
	if (backapp.size() == 0) {
		cout << "khong co tien trinh  nao dang chay" << endl;
		return;
	}
	for(auto itr = backapp.end() - 1; itr >= backapp.begin(); --itr) {
 		// Xử lý
 		const char* d = s.c_str();
		DWORD Id = atoi(d);

		if ( (*itr).info.dwProcessId == Id)
		{
			SuspendThread( (*itr).info.hThread );
			(*itr).status--;
			cout << " da dung tien trinh: "<< (*itr).info.dwProcessId << "---" << (*itr).name << endl;
			return;
		}
	}
	cout << "khong tim duoc tien trinh" << endl;
}

void Resume (string s) {
	if (backapp.size() == 0) {
		cout << "khong co tien trinh  nao dang chay" << endl;
		return;
	}
	for(auto itr = backapp.end() - 1; itr >= backapp.begin(); --itr) {
 		// Xử lý
 		const char* d = s.c_str();
		DWORD Id = atoi(d);

		if ( (*itr).info.dwProcessId == Id)
		{
			ResumeThread( (*itr).info.hThread );
			(*itr).status++;
			cout << " tiep tuc tien trinh: "<< (*itr).info.dwProcessId << "---" << (*itr).name << endl;
			return;
		}
	}
	cout << "khong tim duoc tien trinh" << endl;
}

 