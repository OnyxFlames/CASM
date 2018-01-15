#pragma once

#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_SUFFIX "indev"
#define VERSION_COMPLETE \
std::string(\
std::to_string(VERSION_MAJOR) + "." +\
std::to_string(VERSION_MINOR) + " " +\
VERSION_SUFFIX)

#define PLATFORM "Windows"