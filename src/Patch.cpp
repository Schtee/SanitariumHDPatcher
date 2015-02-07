#include "Patch.h"

#include <memoryapi.h>

Patch::Patch(const AddressType address,
	const Bytes& bytes) : 
		_address(address),
		_bytes(bytes)
{
}

void Patch::apply(HANDLE hProcess)
{
	SIZE_T bytesWritten;
	WriteProcessMemory(hProcess,
		(LPVOID)_address,
		(LPCVOID)&_bytes[0],
		_bytes.size(),
		&bytesWritten);
}