#include "ArgumentHandler.hpp"

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

ArgumentHandler::ArgumentHandler(int _argc, char * _argv[])
{
	prog_name = _argv[0];
	for (int i = 1; i < _argc; i++)
		arguments.push_back(_argv[i]);
}

void ArgumentHandler::eval()
{
	for (size_t i = 0; i < arguments.size(); i++)
	{
		if (arguments[i] == "-o" && (i + 1) <= arguments.size())
		{
			flags.output_file = arguments[++i];
		}
		if (arguments[i] == "-Sc" && (i + 1) <= arguments.size())
		{
			flags.emit_preprocessed_c = false;
			flags.emit_c = true;
			flags.emit_asm = false;
			flags.run = false;
		}
		if (arguments[i] == "-Se" && (i + 1) <= arguments.size())
		{
			flags.emit_preprocessed_c = true;
			flags.emit_c = false;
			flags.emit_asm = false;
			flags.run = false;
		}
		if (arguments[i] == "-S" && (i + 1) <= arguments.size())
		{
			flags.emit_preprocessed_c = false;
			flags.emit_asm = true;
			flags.emit_c = false;
			flags.run = false;
		}
		else
		{
			if (fs::exists(arguments[i]) && flags.looking_for_input)
			{
				flags.input_file = arguments[i];
				flags.looking_for_input = false;
			}
		}
	}
}

ArgumentHandler::~ArgumentHandler()
{
}
