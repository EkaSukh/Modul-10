#include <iostream>

void printWinRelease();
#if defined (__linux__)//if linux operation system environment 

#include <sys/utsname.h> 

void printVersionLinux() {
        struct utsname utsname; // объект для структуры типа utsname

        uname(&utsname); // передаем объект по ссылке

        std::cout << "OS name: " << utsname.sysname << std::endl; 
        std::cout << "OS version: " << utsname.version << std::endl; 
        std::cout << std::endl;
       
}

#elif defined (_WIN32)//if Windows operation system environment 
#include <windows.h>
#include <VersionHelpers.h>
void printVersionWind32() {
        std::cout << "Windows 32-bit\n";
        printWinRelease();

        //part for PID
        unsigned long int process_p = GetCurrentProcessId();
        std::cout << "The current process ID is " << process_p << std::endl;
        std::cout << std::endl;
}
#elif defined (_WIN64)
#include <windows.h>
#include <VersionHelpers.h>
void printVersionWind64() {
        std::cout << "Windows 64-bit\n";
        printWinRelease();

        //part for PID 
        unsigned long int process_p = GetCurrentProcessId();
        std::cout << "The current process ID is " << process_p << std::endl;
        std::cout << std::endl;
}
#endif

//functin to print Windows release version
void printWinRelease()
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
        printf("Windows_8_Or_Greater\n");
    }
    else if (IsWindows7SP1OrGreater())
    {
        printf("Windows7SP1_Or_Greater\n");
    }
    else if (IsWindows7OrGreater())
    {
        printf("Windows7_Or_Greater\n");
    }
    else if (IsWindowsVistaSP2OrGreater())
    {
        printf("VistaSP2_Or_Greater\n");
    }
    else if (IsWindowsVistaSP1OrGreater())
    {
        printf("VistaSP1_Or_Greater\n");
    }
    else if (IsWindowsVistaOrGreater())
    {
        printf("Vista_Or_Greater\n");
    }
    else if (IsWindowsXPSP3OrGreater())
    {
        printf("XPSP3_Or_Greater\n");
    }
    else if (IsWindowsXPSP2OrGreater())
    {
        printf("XPSP2_Or_Greater\n");
    }
    else if (IsWindowsXPSP1OrGreater())
    {
        printf("XPSP1_Or_Greater\n");
    }
    else if (IsWindowsXPOrGreater())
    {
        printf("XP_Or_Greater\n");
    }
    else
    {
        printf("Client\n");
    }
}
