#include <string>
#include <windows.h>
using namespace std;
int main(int argc, char** argv) {
	char h[2];
	MessageBox(NULL, h, "Caption", MB_OKCANCEL);
	return 0;
}