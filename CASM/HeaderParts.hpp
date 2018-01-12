#pragma once

#define CASM_HEADER "// HEADERS\n#include <stdio.h>\n#include <stdlib.h>\n#include <stdint.h>\n"
#define CASM_DATATYPES "// DATATYPE DEFINITIONS\n" \
	"typedef uint8_t u8;\ntypedef int8_t i8;\ntypedef uint8_t u8;\ntypedef int16_t i16;\ntypedef uint16_t u16;\n" \
	"typedef int32_t i32;\ntypedef uint32_t u32;\ntypedef int64_t i64;\ntypedef uint64_t u64;\n" \
	"typedef float f32;\ntypedef double f64;\n"

#define CASM_FUNCTIONAL "// FUNCTIONAL\nenum\n{\nfalse = 0,\ntrue = 1\n};\nchar\n_jump = false;\n"

#define CASM_ENTRY "// ENTRY\n" \
	"int main\n(\n\tint argc,\n\tchar* argv[]\n){\n"
#define CASM_FOOTER "\n}"