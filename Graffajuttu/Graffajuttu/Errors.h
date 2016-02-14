#pragma once
#include <string>

//has to be extern in order for the compiler to know where the function is (not a class!)
extern void fatalError(std::string errorStr);