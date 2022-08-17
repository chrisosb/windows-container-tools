#include "pch.h"

void
XmlOutputWriter::Begin()
{}

void
XmlOutputWriter::End()
{}

void
XmlOutputWriter::BeginObject(
	_In_ std::wstring Name
)
{
	PushName(Name);

	m_oss << "<" << Name;
	m_writePropertiesAsAttributes = true;
}

void
XmlOutputWriter::EndObject()
{
	std::wstring name = PopName();

	if (m_writePropertiesAsAttributes)
	{
		m_oss << "/>";
		m_writePropertiesAsAttributes = false;
	}
	else
	{
		m_oss << "</" << name << ">";
	}
}

void
XmlOutputWriter::WriteProperty(
	_In_ std::wstring Name,
	_In_ std::wstring Value
)
{
	if (m_writePropertiesAsAttributes)
	{
		// close off element
		m_oss << ">";
		m_writePropertiesAsAttributes = false;
	}

	std::wstring safeValue = ReplaceAll(Value, L"&", L"&amp;").c_str();
	safeValue = ReplaceAll(safeValue, L"<", L"&lt;").c_str();
	safeValue = ReplaceAll(safeValue, L">", L"&gt;").c_str();

	m_oss << "<" << Name << ">" << safeValue << "</" << Name << ">";
}

void
XmlOutputWriter::WriteAttributeOrProperty(
	_In_ std::wstring Name,
	_In_ std::wstring Value
)
{
	if (m_writePropertiesAsAttributes)
	{
		m_oss << " " << Name << "=\"" << Value << "\"";
	}
	else
	{
		WriteProperty(Name, Value);
	}
}

void
XmlOutputWriter::WriteText(
	_In_ std::wstring Value
)
{
	if (m_writePropertiesAsAttributes)
	{
		// close off element
		m_oss << ">";
		m_writePropertiesAsAttributes = false;
	}

	std::wstring safeValue = ReplaceAll(Value, L"&", L"&amp;").c_str();
	safeValue = ReplaceAll(safeValue, L"<", L"&lt;").c_str();
	safeValue = ReplaceAll(safeValue, L">", L"&gt;").c_str();

	m_oss << safeValue;
}