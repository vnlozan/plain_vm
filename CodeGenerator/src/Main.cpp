#include <string>
#include "Interpreter.h"


int main() {
	std::string fileLocation = "../res/instructions.bin";

    std::ofstream file;
    file.open( fileLocation, std::ios::binary | std::ios::trunc );

    VM::Instruction instr = VM::Instruction::LITERAL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    VM::Value v{ VM::ValueType::VT_INT, 10 };
    file.write( ( char* ) &v, sizeof( v ) );

    instr = VM::Instruction::LITERAL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    v.intValue = 20;
    file.write( ( char* ) &v, sizeof( v ) );

    instr = VM::Instruction::INT_MUL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    instr = VM::Instruction::LITERAL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    v.intValue = 200;
    file.write( ( char* ) &v, sizeof( v ) );

    instr = VM::Instruction::INT_EQUAL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    // IF NOT EQUAL BLOCK
    instr = VM::Instruction::LITERAL;
    file.write( ( char* ) &instr, sizeof( instr ) );

    v.intValue = sizeof( VM::Instruction );
    file.write( ( char* ) &v, sizeof( v ) );

    instr = VM::Instruction::SKIP;
    file.write( ( char* ) &instr, sizeof( instr ) );
    //

    // IF EQUAL, will be skipped if not equal
    instr = VM::Instruction::SPAWN_PARTICLES;
    file.write( ( char* ) &instr, sizeof( instr ) );
    //

    instr = VM::Instruction::PLAY_SOUND;
    file.write( ( char* ) &instr, sizeof( instr ) );

    file.close();

	return 0;
}