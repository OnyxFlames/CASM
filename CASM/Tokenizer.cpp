#include "Tokenizer.hpp"

#include "Compiler.hpp"

#include <map>

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

std::vector<Token> tokenize2(std::string file)
{
	std::ifstream f;
	f.open(file);
	std::string buffer = "";
	std::vector<Token> ret;
	while (f >> buffer)
	{
		if (buffer[0] == '"' && buffer[buffer.size() - 1] != '"')
		{
			while (buffer[buffer.size() - 1] != '\"')
			{
				buffer += f.get();
			}
		}
		if (buffer.find_first_not_of("0123456789") == std::string::npos)
			ret.push_back(Token(IntegerConstant, buffer));
		else if (is_datatype(buffer))
			ret.push_back(Token(Datatype, buffer));
		else if (buffer.find_first_not_of("0123456789.f") == std::string::npos)
			ret.push_back(Token(FloatConstant, buffer));
		else if (is_opcode(buffer))
			ret.push_back(Token(Opcode, buffer));
		else if (buffer[0] == '"' && buffer[buffer.size()-1] == '"')
			ret.push_back(Token(StringConstant, buffer));
		else 
			ret.push_back(Token(Identifier, buffer));
	}
	return ret;
}

std::string to_token_name(TokenType _tt)
{
	std::map<TokenType, std::string> token_types
	{
		{Unknown, "Unknown"},
		{Opcode, "Opcode"},
		{Datatype,  "Datatype"},
		{Identifier, "Identifier"},
		{IntegerConstant, "IntegerConstant"},
		{FloatConstant, "FloatConstant"},
		{StringConstant, "StringConstant"}

		/*{"Unknown", Unknown},
		{"Opcode", Opcode},
		{"Datatype", Datatype},
		{"IntegerConstant", IntegerConstant},
		{"FloatConstant", FloatConstant},
		{"StringConstant", StringConstant}*/
	};
	return token_types[_tt];
}
