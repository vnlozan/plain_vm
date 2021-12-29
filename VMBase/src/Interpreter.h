#include <stack>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "Instruction.h"
#include "Value.h"

namespace VM {
	class Interpreter {
	public:
		void process( const std::string& filePath ) {
			Value value;
			Instruction instruction;
			std::ifstream file;

			file.open( filePath, std::ios::in | std::ios::binary );
			file.read( ( char* ) &instruction, sizeof( instruction ) );
            while( !file.eof() ) {

                switch( instruction ) {
                    case Instruction::LITERAL: {
                            file.read( ( char* ) &value, sizeof( value ) );

                            //switch( value.type ) {
                            //    case ValueType::VT_INT: std::cout << "Literal is: " << value.intValue << std::endl; break;
                            //    case ValueType::VT_BOOL: std::cout << "Literal is: " << std::boolalpha << value.boolValue << std::endl; break;
                            //    case ValueType::VT_DOUBLE: std::cout << "Literal is: " << value.doubleValue << std::endl; break;
                            //}

                            m_Stack.push( value );
                            break;
                        }
                    case Instruction::INT_MUL: {
                            uint32_t l1 = m_Stack.top().intValue;
                            m_Stack.pop();

                            uint32_t l2 = m_Stack.top().intValue;
                            m_Stack.pop();

                            std::cout << "Multiplication: " + std::to_string( l1 ) << " and " + std::to_string( l2 ) << std::endl;
                            std::cout << "The result is: " + std::to_string( l1 * l2 ) << std::endl;

                            m_Stack.push( Value{ ValueType::VT_INT, ( l1 * l2 ) } );
                            break;
                        }
                    case Instruction::SET_HEALTH: {
                            uint32_t l = m_Stack.top().intValue;
                            m_Stack.pop();
                            std::cout << "Set health to: " + std::to_string( l ) << std::endl;
                            break;
                        }
                    case Instruction::INT_EQUAL: {
                            uint32_t l1 = m_Stack.top().intValue;
                            m_Stack.pop();

                            uint32_t l2 = m_Stack.top().intValue;
                            m_Stack.pop();

                            std::cout << "Int equal result is: " << std::boolalpha << ( l1 == l2 ) << std::endl;

                            m_Stack.push( Value{ ValueType::VT_BOOL, ( l1 == l2 ) } );

                            break;
                        }
                    case Instruction::SKIP: {
                            uint32_t bytesToSkip = m_Stack.top().intValue;
                            m_Stack.pop();

                            bool isEqual = m_Stack.top().intValue;
                            m_Stack.pop();

                            if( !isEqual ) {
                                file.ignore( bytesToSkip );
                            }
                            break;
                        }
                    case Instruction::SPAWN_PARTICLES: std::cout << "SPAWN PARTICLES" << std::endl; break;
                    case Instruction::PLAY_SOUND: std::cout << "PLAY SOUND" << std::endl;
                }
                file.read( ( char* ) &instruction, sizeof( instruction ) );
            }
            file.close();
		}
	private:
		std::stack<Value> m_Stack;
	};
}