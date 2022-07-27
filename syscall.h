#include <iostream>

#if defined (__linux__)
#include <sys/utsname.h> 

void printVersionLinux() {
        struct utsname utsname; // объект для структуры типа utsname

        uname(&utsname); // передаем объект по ссылке

        std::cout << "OS name: " << utsname.sysname << std::endl; 
        std::cout << "OS version: " << utsname.version << std::endl; 
        std::cout << std::endl;
       
}

#elif defined (_WIN32)

void printVersionWind32() {
        std::cout << "Windows 32-bit\n";
}
#elif defined (_WIN64)

void printVersionWind64() {
        std::cout << "Windows 64-bit\n";
}
#endif
