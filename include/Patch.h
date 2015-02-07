#pragma once

#include "Types.h"

#include <Windows.h>

#include <cstdint>

class Patch
{
public:
	typedef uint32_t AddressType;

	Patch(const AddressType address,
		const Bytes& bytes);

	void apply(HANDLE hProcess);
private:
	const AddressType _address;
	const Bytes _bytes;
};