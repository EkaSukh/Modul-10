#include <iostream>

#if defined(_WIN32)
#include <windows.h>
#include <VersionHelpers.h>
#elif defined(_WIN64)
#include <windows.h>
#include <VersionHelpers.h>
#endif

int main()
{
#if defined(_WIN32)
	std::cout << "Wndows_32 ";
#elif defined(_WIN64)
	std::cout << "Wndows_64 ";
#endif

	{     

        if (IsWindowsServer())
        {
            printf("Server\n");
        }
        else if (IsWindows10OrGreater())
        {
            printf("Windows_10_Or_Greater\n");
        }
        else if (IsWindows8Point1OrGreater())
        {
            printf("Windows_8_Point1_Or_Greater\n");
        }
        else if (IsWindows8OrGreater())
        {
            printf("Windows_8_OrGreater\n");
        }
        else if (IsWindows7SP1OrGreater())
        {
            printf("Windows7SP1OrGreater\n");
        }
        else if (IsWindows7OrGreater())
        {
            printf("Windows7OrGreater\n");
        }
        else if (IsWindowsVistaSP2OrGreater())
        {
            printf("VistaSP2OrGreater\n");
        }
        else if (IsWindowsVistaSP1OrGreater())
        {
            printf("VistaSP1OrGreater\n");
        }
        else if (IsWindowsVistaOrGreater())
        {
            printf("VistaOrGreater\n");
        }
        else if (IsWindowsXPSP3OrGreater())
        {
            printf("XPSP3OrGreater\n");
        }
        else if (IsWindowsXPSP2OrGreater())
        {
            printf("XPSP2OrGreater\n");
        }
        else if (IsWindowsXPSP1OrGreater())
        {
            printf("XPSP1OrGreater\n");
        }
        else if (IsWindowsXPOrGreater())
        {
            printf("XPOrGreater\n");
        }
        else
        {
            printf("Client\n");
        }
	}

	unsigned long int process_p = GetCurrentProcessId();
	std::cout << "The current process ID is " << process_p << std::endl;

	return 0;
}