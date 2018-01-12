#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#include "HeaderParts.hpp"

const std::string compile(const std::vector<std::string> inst);

const std::string get_header();
const std::string get_datatypes();
const std::string get_functional();
const std::string get_entry();
const std::string get_footer();
