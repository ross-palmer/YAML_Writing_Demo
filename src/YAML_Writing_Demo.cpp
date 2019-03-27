#include <iostream>
#include "YAMLWriter.h"

#ifdef _DEBUG 
#pragma comment(lib,"libyaml-cppmdd.lib")
#else 
#pragma comment(lib,"libyaml-cppmd.lib")
#endif

// Very simple demonstration program showing how to write a high score table in 
//  a structured YAML format.
int main()
{
	YAMLWriter::write();
	system("PAUSE");
}
