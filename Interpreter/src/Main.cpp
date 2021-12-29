#include <string>
#include "Interpreter.h"

int main() {
	std::string file = "../res/instructions.bin";

	VM::Interpreter interpreter;

	interpreter.process( file );

	return 0;
}