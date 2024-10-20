#include "iostream"
#include "memory.h"

int main() {
    HANDLE pHandle = memory::getProcessHandle("windowClassName");

    /*int ammo;
    DWORD address = 0x00771128;
    memory::read(pHandle, address, ammo);*/

    CloseHandle(pHandle);

    return 0;
}