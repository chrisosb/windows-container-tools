#include "pch.h"

void
OutputWriter::PushName(std::wstring Name)
{
	m_names.push(Name);
}

std::wstring
OutputWriter::PopName()
{
	std::wstring result = m_names.top();
	m_names.pop();

	return result;
}

std::wstring
OutputWriter::ToString()
{
	return m_oss.str();
}

