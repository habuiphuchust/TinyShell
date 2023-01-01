#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void getDate() {
    SYSTEMTIME st, lt;
    
    GetSystemTime(&st);
    GetLocalTime(&lt);
    
    cout << "The system date is: "<<st.wMonth<<"/"<<st.wDay<<"/"<<st.wYear<< endl;
    cout << "The local date is: " <<lt.wMonth<<"/"<<lt.wDay<<"/"<<lt.wYear<< endl;

}

void getTime() {
	SYSTEMTIME st, lt;
    
    GetSystemTime(&st);
    GetLocalTime(&lt);
    
    cout << "The system time is: "<<st.wHour<< "h:" <<st.wMinute<<"m:"<<st.wSecond<<"s:"<<st.wMilliseconds<<"ms"<< endl;
    cout << "The local time is: " <<lt.wHour<< "h:" <<lt.wMinute<<"m:"<<lt.wSecond<<"s:"<<lt.wMilliseconds<<"ms"<< endl;
}

void addPath(string &path, string newPath) {
	path = newPath;
}

void createForeGround(const char* link) {
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

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
