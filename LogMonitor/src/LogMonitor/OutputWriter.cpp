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

std::wstring
OutputWriter::ReplaceAll(std::wstring Str, const std::wstring& From, const std::wstring& To)
{
    size_t start_pos = 0;

    while ((start_pos = Str.find(From, start_pos)) != std::string::npos) {
        Str.replace(start_pos, From.length(), To);
        start_pos += To.length(); // Handles case where 'To' is a substring of 'From'
    }
    return Str;
}
