#pragma once

#include "PatchCollection.h"

#include <map>
#include <string>

class PatchesJSONParser
{
public:
	typedef std::map<std::string, Bytes> VariableMap;
	typedef std::map<std::string, PatchCollection> PatchCollectionsByHash;

	PatchCollectionsByHash parse(const std::string& json,
		const VariableMap& variablesByName);
};