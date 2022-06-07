#pragma once
#include "pch.h"
using namespace std;

std::unique_ptr<OutputWriter>
OutputWriterFactory::CreateOutputWriter(bool jsonOuput)
{
	if (jsonOuput)
	{
		return make_unique<JsonOutputWriter>();
	}
	else
	{
		return make_unique<XmlOutputWriter>();
	}
}