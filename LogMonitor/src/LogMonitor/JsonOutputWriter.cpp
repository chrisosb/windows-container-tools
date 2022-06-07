#include "pch.h"

void
JsonOutputWriter::Begin()
{
	m_oss << "{";
	m_requiresComma = false;
}

void
JsonOutputWriter::End()
{
	m_oss << "}";
	m_requiresComma = false;
}

void
JsonOutputWriter::BeginObject(
	_In_ std::wstring Name
)
{
	PushName(Name);

	if (m_requiresComma)
	{
		m_oss << ",";
	}

	m_oss << "\"" << Name << "\":{";
	m_requiresComma = false;
}

void
JsonOutputWriter::EndObject()
{
	PopName();

	m_oss << "}";	
	m_requiresComma = true;
}

void
JsonOutputWriter::WriteProperty(
	_In_ std::wstring Name,
	_In_ std::wstring Value
)
{
	if (m_requiresComma)
	{
		m_oss << ",";
	}

	m_oss << "\"" << Name << "\":\"" << Value << "\"";
	m_requiresComma = true;
}

void
JsonOutputWriter::WriteAttributeOrProperty(
	_In_ std::wstring Name,
	_In_ std::wstring Value
)
{
	WriteProperty(Name, Value);
}

void
JsonOutputWriter::WriteText(
	_In_ std::wstring Value
)
{
	std::wstring name = m_names.top();
	WriteProperty(name, Value);
}

