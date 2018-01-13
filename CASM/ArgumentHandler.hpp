#pragma once


#include <vector>
#include <string>
#include <iostream>

struct FlagStruct
{
	bool looking_for_input = true;
	bool run = true;
	bool compile = true;
	bool emit_asm = false;
	bool emit_c = false;
	bool emit_preprocessed_c = false;
	// technically it does emit c,
	// but this flags tells the compiler not to remove it after
	std::string output_file = "output.exe";
	std::string input_file = "";
};

class ArgumentHandler
{
private:
	std::string prog_name = "Unknown";
	FlagStruct flags;
	std::vector<std::string> arguments;
public:
	ArgumentHandler(int _argc, char* _argv[]);
	void eval();
	FlagStruct& get_flags() { return flags; }
	~ArgumentHandler();
};

