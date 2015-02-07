#include "PatchCollection.h"

void PatchCollection::add(const Patch& patch)
{
	_patches.push_back(patch);
}

void PatchCollection::apply(HANDLE hProcess)
{
	for (auto patch : _patches)
	{
		patch.apply(hProcess);
	}
}