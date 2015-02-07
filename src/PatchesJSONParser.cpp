#include "PatchesJSONParser.h"

#include "rapidjson/document.h"

#include <sstream>

using namespace rapidjson;

PatchesJSONParser::PatchCollectionsByHash 
	PatchesJSONParser::parse(const std::string& json,
		const VariableMap& variablesByName)
{
	PatchCollectionsByHash patchCollectionsByHash;

	Document doc;
	doc.Parse(json.c_str());

	Value& patchesByHash = doc["patchesByHash"];

	for (Value::ConstMemberIterator hashIt = patchesByHash.MemberBegin(); hashIt != patchesByHash.MemberEnd(); ++hashIt)
	{
		PatchCollection patchCollection;

		const Value& patches = hashIt->value;

		for (Value::ConstValueIterator patchIt = patches.Begin(); patchIt != patches.End(); ++patchIt)
		{
			const Value& patch = *patchIt;

			const Value& variableName = patch["variable"];

			const VariableMap::const_iterator varIt = variablesByName.find(variableName.GetString());

			if (varIt == variablesByName.end())
				continue;

			const Value& addressString = patch["address"];
			std::stringstream ss;
			ss << addressString.GetString();
			int address;
			ss >> std::hex >> address;

			patchCollection.add(Patch(address,
				varIt->second));
		}

		const std::string hash(hashIt->name.GetString());
		patchCollectionsByHash.insert(std::pair<std::string, PatchCollection>(hash, patchCollection));
	}

	return patchCollectionsByHash;
}