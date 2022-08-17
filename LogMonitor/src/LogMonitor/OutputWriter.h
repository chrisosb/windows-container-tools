#pragma once
#include <stack>
class OutputWriter
{
protected:
	std::wostringstream m_oss;
	std::stack<std::wstring> m_names;
public:	
	virtual void Begin() = 0;

	virtual void End() = 0;

	virtual void BeginObject(
		_In_ std::wstring Name
	) = 0;

	virtual void EndObject() = 0;

	virtual void WriteProperty(
		_In_ std::wstring Name,
		_In_ std::wstring Value
	) = 0;

	virtual void WriteAttributeOrProperty(
		_In_ std::wstring Name,
		_In_ std::wstring Value
	) = 0;

	virtual void WriteText(
		_In_ std::wstring Value
	) = 0;


	void PushName(std::wstring);
	std::wstring PopName();
	std::wstring ToString();
	std::wstring ReplaceAll(std::wstring Str, const std::wstring& From, const std::wstring& To);
};

