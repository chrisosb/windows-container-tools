#pragma once
class OutputWriterFactory
{
public:
	static std::unique_ptr<OutputWriter> CreateOutputWriter(bool jsonOuput);
};