// Hellocmake.cpp : Defines the entry point for the application.
//

#include "Hellocmake.h"

#if defined(__unix__) || defined(unix) || defined(__unix)
	#define PLATFORM "Linux"
	#define OS_Linux 1
	#include <sys/sysinfo.h>

#elif defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
	#define PLATFORM "Windows"
	#define OS_Windows 1
	#include <Windows.h>

#else
	#define PLATFORM "Unknown OS"
	
#endif

using namespace std;

void getMemorySize()
{

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)

	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	cout << status.ullTotalPhys / (1024 * 1024 * 1024) + 1 << " GB Memory";

#elif  defined(__unix__) || defined(unix) || defined(__unix)

	struct sysinfo myinfo;
	unsigned long  total_bytes;
	sysinfo(&myinfo);
	total_bytes = myinfo.mem_unit * myinfo.totalram;
	cout << total_bytes / 1024 / 1024 << " MB";

#endif

}


int main()
{

	cout << PLATFORM << endl ;
	 
	getMemorySize();

	return 0;
}



