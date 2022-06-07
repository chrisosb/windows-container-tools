#pragma once
class JsonOutputWriter final : public OutputWriter
{
	bool m_requiresComma = false;

public:
	void Begin();

	void End();

	void BeginObject(
		_In_ std::wstring Name
	);

	void EndObject();

	void WriteProperty(
		_In_ std::wstring Name,
		_In_ std::wstring Value
	);

	void WriteAttributeOrProperty(
		_In_ std::wstring Name,
		_In_ std::wstring Value
	);

	void WriteText(
		_In_ std::wstring Value
	);
};

