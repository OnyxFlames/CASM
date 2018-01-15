#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Token.hpp"

std::vector<std::string> tokenize(std::string file);

std::vector<Token> tokenize2(std::string file);

std::string to_token_name(TokenType _tt);