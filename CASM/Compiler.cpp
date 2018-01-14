#include "Compiler.hpp"

#include <array>

bool is_datatype(const std::string dt)
{
	// Datatype table
	std::array<const char*, 12> datatypes
	{
		"i8", "u8", "i16", "u16",
		"i32", "u32", "i64", "u64",
		"f32", "f64", "u8*", "memptr",
	};
	for (const auto& _dt : datatypes)
		if (dt == _dt) return true;
		else continue;
	return false;
}

const std::string compile(const std::vector<std::string> inst)
{
	std::string output = "";
	uintmax_t line_number = 0;
	for (size_t i = 0; i < inst.size(); i++)
	{
		line_number++;
		// is def and has two arguments for it.
		if (inst[i] == "def" && (i + 2) <= inst.size())
		{
			line_number--;
			
			if (!is_datatype(inst[i + 1]))
			{
				std::cerr << "Error: '" << inst[i + 1] << "' is not a datatype in CASM.\n"; std::exit(1);
			}

			if (inst[i + 1] == "u8*")
				output += "char* " + inst[i + 2] + ";\n";
			else if (inst[i + 1] == "memptr")
				output += "i64 " + inst[i + 2] + ";\n";
			else
				output += inst[i + 1] + " " + inst[i + 2] + ";\n";
			i += 2;
		}
		if (inst[i] == "printf" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			if ((inst[i + 1])[0] == '"' && (inst[i + 1])[inst[i + 1].size()-1] == '"')
				output += "fprintf\n(\nstdout,\n" + inst[i + 1] + ",\n" + inst[i + 2] + "\n);\n";
			else
				output += "fprintf\n(\nstdout,\n\"" + inst[i + 1] + "\",\n" + inst[i + 2] + "\n);\n";
			i += 2;
		}
		if (inst[i] == "scanf" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "scanf(\"" + inst[i + 1] + "\", &" + inst[i + 2] + ");\n";
			i += 2;
		}
		if (inst[i] == "load" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 1] + " = " + inst[i + 2] + ";\n";
			i += 2;
		}
		/*if (inst[i] == "loadp" && (i + 2) <= inst.size())
		{
			//output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "(" + inst[i + 1] + ") = " + inst[i + 2] + ";\n";
			i += 2;
		}*/
		/*if (inst[i] == "loadaddr" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 1] + " = &" + inst[i + 2] + ";\n";
			i += 2;
		}*/
		if (inst[i] == "add" && (i + 3) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 3] + " = " + inst[i + 1] + " + " + inst[i + 2] + ";\n";
			i += 3;
		}
		if (inst[i] == "sub" && (i + 3) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 3] + " = " + inst[i + 1] + " - " + inst[i + 2] + ";\n";
			i += 3;
		}
		if (inst[i] == "mul" && (i + 3) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 3] + " = " + inst[i + 1] + " * " + inst[i + 2] + ";\n";
			i += 3;
		}
		if (inst[i] == "div" && (i + 3) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 3] + " = " + inst[i + 1] + " / " + inst[i + 2] + ";\n";
			i += 3;
		}
		if (inst[i] == "exp" && (i + 3) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 3] + " = pow(" + inst[i + 1] + ", " + inst[i + 2] + ");\n";
			i += 3;
		}
		if (inst[i] == "eq" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " == " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "neq" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " != " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "lt" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " < " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "gt" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " >= " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "lte" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " < " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "gte" && (i + 2) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";

			output += "if (" + inst[i + 1] + " >= " + inst[i + 2] + ")\n";
			output += "_jump = true;\nelse\n_jump = false;\n";

			i += 2;
		}
		if (inst[i] == "inc" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 1] + "++;\n";
			i++;
		}
		if (inst[i] == "dec" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += inst[i + 1] + "--;\n";
			i++;
		}
		if (inst[i] == "jmp" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			long jmp_adder = std::stol(inst[i + 1]);
			if (jmp_adder == 0)
			{
				output += "if\n(_jump)\n";
				output += "{\n\t_jump = false;\n\tgoto _LINE_" + std::to_string(line_number + 1) + ";\n}\n";
			}
			else
			{
				output += "if\n(_jump)\n";
				output += "{\n\t_jump = false;\n\tgoto _LINE_" + std::to_string(line_number + jmp_adder) + ";\n}\n";
			}
			i++;
		}
		if (inst[i] == "ujmp" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			long jmp_adder = std::stol(inst[i + 1]);
			if (jmp_adder == 0)
			{
				output += "goto _LINE_" + std::to_string(line_number + 1) + ";\n";
			}
			else
				output += "goto _LINE_" + std::to_string(line_number + jmp_adder) + ";\n";
			i++;
		}
		/*if (inst[i] == "alloc" && (i + 2) <= inst.size())
		{
			output += "void* " + inst[i + 1] + " = malloc(" + inst[i + 2] + ");\n";
			i += 2;
		}
		if (inst[i] == "free" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "free(" + inst[i + 1] + ");\n";
			i++;
		}*/
		if (inst[i] == "ret" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "return " + inst[i + 1] + ";\n";
			i++;
		}
		if (inst[i] == "hlt" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "exit(" + inst[i + 1] + ");\n";
			i++;
		}
		if (inst[i] == "syscall" && (i + 1) <= inst.size())
		{
			output += "_LINE_" + std::to_string(line_number) + ": ";
			output += "system(" + inst[i + 1] + ");\n";
			i++;
		}
	};
	return output;
}

const std::string get_header()
{
	return CASM_HEADER;
}

const std::string get_datatypes()
{
	return CASM_DATATYPES;
}
const std::string get_functional()
{
	return CASM_FUNCTIONAL;
}
const std::string get_entry()
{
	return CASM_ENTRY;
}
const std::string get_footer()
{
	return CASM_FOOTER;
}