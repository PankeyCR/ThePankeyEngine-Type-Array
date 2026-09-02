#pragma once

#include "ArrayPointer.hpp"
#include "ByteArray.hpp"
#include "CharArray.hpp"
#include "CharPointer.hpp"

#if defined(pankey_Log) && (defined(to_CharArray_CharPointer_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
	#include "Logger_status.hpp"
	#define to_CharArray_CharPointerLog(status,method,mns) pankey_Log(status,"to_CharArray_CharPointer",method,mns)
#else
	#define to_CharArray_CharPointerLog(status,method,mns)
#endif

namespace pankey{

	namespace Type{

		namespace Array{

			CharArray toCharArray(const CharPointer& a_charpointer){
				to_CharArray_CharPointerLog(pankey_Log_StartMethod, "toCharArray", "const CharPointer&");
				if(a_charpointer.isEmpty()){
					to_CharArray_CharPointerLog(pankey_Log_EndMethod, "toCharArray", "a_charpointer.isEmpty()");
					return CharArray();
				}
				CharArray i_array;
				i_array.createArrayFast(a_charpointer.length());
				for(int x = 0; x < a_charpointer.length(); x++){
					i_array.addFast(a_charpointer.get(x));
				}
				to_CharArray_CharPointerLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharPointer toCharPointer(const CharArray& a_chararray){
				to_CharArray_CharPointerLog(pankey_Log_StartMethod, "toCharPointer", "const CharArray&");
				to_CharArray_CharPointerLog(pankey_Log_EndMethod, "toCharPointer", "");
				return CharPointer(a_chararray.getArrayPointer(), a_chararray.length());
			}
		}
		
	}
		
}