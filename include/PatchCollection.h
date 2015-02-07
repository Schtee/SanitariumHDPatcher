#pragma once

#include "Patch.h"

class PatchCollection
{
public:
	void add(const Patch& patch);
	void apply(HANDLE hProcess);
private:
	std::vector<Patch> _patches;
};