#include "ArgumentHandler.hpp"

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

ArgumentHandler::ArgumentHandler(int _argc, char * _argv[])
{
	prog_name = _argv[0];
	if (_argc == 1)
		print_help();
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
		if (arguments[i] == "--tokenize" && (i + 1) <= arguments.size())
		{
			flags.emit_preprocessed_c = false;
			flags.emit_asm = false;
			flags.emit_c = false;
			flags.run = false;
			flags.tokenize = true;
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

void ArgumentHandler::print_help()
{
	std::cout << prog_name << " <file> <flags>\n"
		"-o <value> - rename output file\n"
		"-Sc - emit 'c-assembly' to output file\n"
		"-S - emit assembly to output file\n"
		"-Se - emit proprocessed C to output file\n";
	std::exit(1);
}

ArgumentHandler::~ArgumentHandler()
{
}
