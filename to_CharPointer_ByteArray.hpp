#pragma once

	#include "ArrayPointer.hpp"
	#include "CharArray.hpp"
	#include "CharPointer.hpp"
	#include "ByteArray.hpp"
	#include "CharArrayPrimitive.hpp"

	#if defined(pankey_Log) && (defined(to_CharPointer_ByteArray_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
		#include "Logger_status.hpp"
		#define to_CharPointer_ByteArrayLog(status,method,mns) pankey_Log(status,"to_CharPointer_ByteArray",method,mns)
	#else
		#define to_CharPointer_ByteArrayLog(status,method,mns)
	#endif

	namespace pankey{

		namespace Type{

			namespace Array{

				pankey::Utility::Test::CharPointer toCharPointer(const ByteArray& a_array){
					to_CharPointer_ByteArrayLog(pankey_Log_StartMethod, "toCharPointer", "");
					if(a_array.isEmpty()){
						to_CharPointer_ByteArrayLog(pankey_Log_EndMethod, "toCharPointer", "a_array.isEmpty()");
						return pankey::Utility::Test::CharPointer();
					}
					to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", "length:");
					to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", a_array.length());
					pankey::Utility::Test::CharPointer i_array;
					i_array.create(a_array.length());
					for(int x = 0; x < a_array.length(); x++){
						to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", "Iteration:");
						to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", x);
						char f_chr = (char)a_array.get(x);
						i_array.set(x, f_chr);
						to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", "Adding");
						to_CharPointer_ByteArrayLog(pankey_Log_Statement, "toCharPointer", f_chr);
					}
					to_CharPointer_ByteArrayLog(pankey_Log_EndMethod, "toCharPointer", "");
					return i_array;
				}

				ByteArray toByteArray(const pankey::Utility::Test::CharPointer& a_array){
					ByteArray i_array;
					for(int x = 0; x < a_array.length(); x++){
						i_array.add((Byte)a_array.get(x));
					}
					return i_array;
				}
				
			}
			
		}
			
	}