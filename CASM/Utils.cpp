#include "Utils.hpp"

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

bool is_opcode(const std::string oc)
{
	std::array<const char*, 22> opcodes
	{
		"def", "printf", "scanf", "load",
		"add", "sub", "mul", "div", "exp",
		"eq", "neq", "lt", "gt", "lte", "gte",
		"inc", "dec", "jmp", "ujmp",
		"ret", "hlt", "syscall"
	};
	for (const auto& _oc : opcodes)
		if (oc == _oc) return true;
		else continue;
		return false;
}
