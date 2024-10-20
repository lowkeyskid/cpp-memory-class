#include "Windows.h"

namespace memory
{
    HANDLE getProcessHandle(LPCSTR windowClassName)
    {
        // output the function in use for debugging
        std::cout << "getProcessHandle(LPCSTR windowClassName)" << std::endl;

        // find window from class name
        HWND hWnd = FindWindowA(windowClassName, nullptr);
        std::cout << "[ window ] : " << hWnd << std::endl;

        // find pid from window
        DWORD pid = 0;
        GetWindowThreadProcessId(hWnd, &pid);
        std::cout << "[ pid ]    : " << pid << std::endl;

        // find handle from pid
        HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
        std::cout << "[ handle ] : " << phandle << std::endl << std::endl;

        return phandle;
    }

    template<typename T>
    void read(HANDLE phandle, DWORD address, T& val) {
        // output the function in use for debugging
        std::cout << "read(HANDLE phandle, DWORD address, T& val)" << std::endl;

        // read the address's value
        ReadProcessMemory(phandle, (LPVOID)address, &val, sizeof(val), nullptr);

        // output the address's value
        std::cout << "[Address Value] : " << val << std::endl;
    }
};