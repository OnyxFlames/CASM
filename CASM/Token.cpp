#include "Token.hpp"



Token::Token()
{
}

Token::Token(TokenType _type, std::string _value):
	type(_type),
	value(_value)
{
}


Token::~Token()
{
}
