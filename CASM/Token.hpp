#pragma once

#include <string>

enum TokenType
{
	Unknown = 0,
	Opcode,
	Identifier,
	Datatype,
	IntegerConstant,
	FloatConstant,
	StringConstant,

};

struct Token
{
	Token();
	Token(TokenType _type, std::string _value);
	~Token();
	TokenType type = Unknown;
	std::string value = "";
};

