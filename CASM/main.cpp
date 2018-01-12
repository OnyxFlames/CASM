#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

#include "HeaderParts.hpp"

#include "ArgumentHandler.hpp"

#include "Compiler.hpp"

#include "Tokenizer.hpp"

int main(int argc, char* argv[])
{
	ArgumentHandler ah(argc, argv);
	ah.eval();
	std::string output = get_header();
	output += get_datatypes();
	output += get_functional();
	output += get_entry();

	std::vector<std::string> inst;

	std::ifstream file;
	if (argc < 2)
		inst = tokenize("../test.casm");
	else
		inst = tokenize(ah.get_flags().input_file);
	
	output += compile(inst);
	output += get_footer();
	std::ofstream outputf("output.c");
	outputf << output;
	outputf.close();
	if (ah.get_flags().compile)
	{
		if (fs::exists(ah.get_flags().output_file))
			fs::remove(ah.get_flags().output_file);
		std::string cmd = "gcc output.c -o " + ah.get_flags().output_file;
		system(cmd.c_str());
	}
	if (ah.get_flags().run) {
		if (fs::exists(ah.get_flags().output_file))
		{
			std::cout << "Executing " << ah.get_flags().output_file << "\n" << std::string(32, '-') << '\n';
			system(ah.get_flags().output_file.c_str());
		}
		else
			std::cerr << "Failed to execute code.\n";
	}
	if (ah.get_flags().emit_asm) 
	{
		if (fs::exists(ah.get_flags().output_file))
			fs::remove(ah.get_flags().output_file);
		std::string cmd = "gcc output.c " + std::string("-S -Os") + " -o " + ah.get_flags().output_file;
		system(cmd.c_str());
	}
	if (ah.get_flags().emit_c)
	{
		std::ofstream c_output(ah.get_flags().output_file);
		c_output << output;
		c_output.close();
	}
	return 0;
}