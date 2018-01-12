#include "Tokenizer.hpp"

std::vector<std::string> tokenize(std::string file)
{
	std::ifstream f;
	f.open(file);
	std::string buffer = "";
	std::vector<std::string> ret;
	while (f >> buffer)
	{
		if (buffer[0] == '"' && buffer[buffer.size() - 1] != '"')
		{
			while (buffer[buffer.size() - 1] != '\"')
			{
				buffer += f.get();
			}
		}
		ret.push_back(buffer);
	}
	return ret;
}
