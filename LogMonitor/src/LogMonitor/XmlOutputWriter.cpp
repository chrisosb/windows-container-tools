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

//void
//XmlOutputWriter::EndObject(
//	_In_ std::wstring Name,
//	_In_ std::wstring Value
//)
//{
//	if (m_WritePropertiesAsAttributes)
//	{
//		if (Value != L"")
//		{
//			m_oss << ">" << Value << "</" << Name << ">";
//		}
//		else
//		{
//			m_oss << "/>";
//		}
//
//		m_WritePropertiesAsAttributes = false;
//	}
//	else
//	{
//		if (Value != L"")
//		{
//			m_oss << Value;
//		}
//
//		m_oss << "</" << Name << ">";
//	}	
//}

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

	m_oss << "<" << Name << ">" << Value << "</" << Name << ">";		
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

	m_oss << Value;
}