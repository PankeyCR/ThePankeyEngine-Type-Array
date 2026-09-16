#pragma once

#include "CharArray.hpp"
#include "helper_Char.hpp"
#include "strlen.hpp"
#include "int_strlen.hpp"
#include "long_strlen.hpp"

#if defined(pankey_Log) && (defined(CharArrayPrimitive_Log) || defined(pankey_Global_Log) || defined(pankey_Type_Array_Log))
	#include "Logger_status.hpp"
	#define CharArrayPrimitiveLog(status,method,mns) pankey_Log(status,"CharArrayPrimitive",method,mns)
#else
	#define CharArrayPrimitiveLog(status,method,mns)
#endif

namespace pankey{

	namespace Type{

		namespace Array{

			bool isBool(const CharArray& a_array){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "isBool", "");
				if(a_array.length() == 1){
					if(a_array.get(0) == '1'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "1");
						return true;
					}
					if(a_array.get(0) == '0'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "0");
						return true;
					}
				}
				if(a_array.length() == 4){
					if(a_array.get(0) == 't' && a_array.get(1) == 'r' && a_array.get(2) == 'u' && a_array.get(3) == 'e'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "true");
						return true;
					}
					if(a_array.get(0) == 'T' && a_array.get(1) == 'R' && a_array.get(2) == 'U' && a_array.get(3) == 'E'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "TRUE");
						return true;
					}
				}
				if(a_array.length() == 5){
					if(a_array.get(0) == 'f' && a_array.get(1) == 'a' && a_array.get(2) == 'l' && a_array.get(3) == 's' && a_array.get(4) == 'e'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "false");
						return true;
					}
					if(a_array.get(0) == 'F' && a_array.get(1) == 'A' && a_array.get(2) == 'L' && a_array.get(3) == 'S' && a_array.get(4) == 'E'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "False");
						return true;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "isBool", "Not bool");
				return false;
			}
	
			bool isInt(const CharArray& a_array){ 
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "isInt", "");
				if(a_array.isEmpty()){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isInt", "isEmpty");
					return false;
				}
				int i_start = 0;
				if(a_array.get(0) == '-'){
					if(a_array.length() == 1){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isNegativeInt", "a_array.length() == 1 && -");
						return false;
					}
					i_start = 1;
				}
				for(int i = i_start; i < a_array.length(); i++){
					char f_char = a_array.get(i);
					if(!pankey::Utility::Test::isNumber(f_char)){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isInt", "Not a float");
						return false;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "isInt", "Is a float");
				return true;
			}
			
			bool isPositiveInt(const CharArray& a_array){ 
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "isPositiveInt", "");
				if(a_array.isEmpty()){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isPositiveInt", "isEmpty");
					return false;
				}
				if(a_array.get(0) == '-'){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isPositiveInt", "isEmpty");
					return false;
				}
				for(int i = 0; i < a_array.length(); i++){
					char f_char = a_array.get(i);
					if(!pankey::Utility::Test::isNumber(f_char)){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isPositiveInt", "Not a float");
						return false;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "isPositiveInt", "Is a float");
				return true;
			}
			
			bool isNegativeInt(const CharArray& a_array){ 
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "isNegativeInt", "");
				if(a_array.isEmpty()){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isNegativeInt", "isEmpty");
					return false;
				}
				if(a_array.get(0) != '-'){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isNegativeInt", "isEmpty");
					return false;
				}
				for(int i = 1; i < a_array.length(); i++){
					char f_char = a_array.get(i);
					if(!pankey::Utility::Test::isNumber(f_char)){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isNegativeInt", "Not a float");
						return false;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "isNegativeInt", "Is a float");
				return true;
			}

			bool isLong(const CharArray& a_array){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "isLong", "");
				if(a_array.isEmpty()){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "isLong", "Not a long");
					return false;
				}
				for(int i = 0; i < a_array.length() - 1; i++){
					char f_char = a_array.get(i);
					if(!pankey::Utility::Test::isNumber(f_char)){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "isLong", "Not a long");
						return false;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "isLong", "Is a long");
				return true;
			}
					
			CharArray toCharArray(int a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const int&");
				CharArray i_array;
				int i_size = pankey::Utility::Test::int_strlen(a_value);
				if(i_size <= 0){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
					return i_array;
				}
				i_array.createArrayFast(i_size);
				i_array.setLength(i_size);

				int position = 0;
				bool isNegative = false;
				if(a_value < 0){
					CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "negative value");
					CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "Position: ");
					CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", position);
					isNegative = true;
					a_value *= -1;
					i_array.setFast(position, '-');
					position++;
					i_size--;
				}
				int i_value_reduction = 1;
				int i_reduce_value = 1;
				int i_output_value = 1;
				for(int x = 0; x < i_size; x++){
					int exponent = 1;
					for(int y = 0; y < i_size - x - 1; y++){
						exponent *= 10;
					}
					i_value_reduction = a_value / exponent;
					if(x == 0){
						i_output_value = i_value_reduction;
					}else{
						i_output_value = i_value_reduction - i_reduce_value;
					}
					i_reduce_value = i_value_reduction * 10;
					i_array.setFast(position, i_output_value + 48);
					position++;
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const bool& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const bool&");
				CharArray i_array;
				i_array.createArray(1);
				i_array.set(0, (a_value) ? '1' : '0');
				i_array.setLength(1);
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const char* a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const char*");
				CharArray i_array;
				if(a_value == nullptr){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "a_value == nullptr");
					return i_array;
				}
				int i_size = pankey::Utility::Test::strlen(a_value);
				i_array.createArray(i_size);
				for(int x = 0; x < i_size; x++){
					i_array.setFast(x, a_value[x]);
				}
				i_array.setLength(i_size);
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const long& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const long&");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "a_value");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", a_value);
				
				int i_size = pankey::Utility::Test::long_strlen(a_value);
				if(i_size <= 0){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
					return CharArray();
				}
				CharArray i_array;
				i_array.createArrayFast(i_size);
				i_array.setLength(i_size);

				long i_value = a_value;
				int position = 0;
				bool isNegative = false;
				if(i_value < 0){
					isNegative = true;
					i_value *= -1;
					i_size--;
					i_array.setFast(position, '-');
					position++;
				}
				long n_value = 1;
				long r_value = 1;
				long s_value = 1;
				for(int x = 0; x < i_size; x++){
					long expn = 1;
					for(int y = 0; y < i_size - x - 1; y++){
						expn *= 10;
					}
					n_value = i_value / expn;
					if(x == 0){
						s_value = n_value;
					}else{
						s_value = n_value - r_value;
					}
					r_value = n_value * 10;
					i_array.setFast(position, s_value + 48);
					position++;
				}
						
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const unsigned long long& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const unsigned long long&");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "a_value");

				int i_size = 1;
				unsigned long long i_counter = a_value;
				while(i_counter >= 10){
					i_counter /= 10;
					i_size++;
				}

				CharArray i_array;
				i_array.createArrayFast(i_size);
				i_array.setLength(i_size);

				// Filled from the last digit so no exponent is ever needed.
				unsigned long long i_value = a_value;
				for(int x = i_size - 1; x >= 0; x--){
					i_array.setFast(x, static_cast<char>((i_value % 10) + 48));
					i_value /= 10;
				}

				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const long long& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const long long&");
				if(a_value >= 0){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
					return toCharArray(static_cast<unsigned long long>(a_value));
				}
				// Negated as unsigned so the most negative value cannot overflow.
				const unsigned long long i_magnitude =
					static_cast<unsigned long long>(-(a_value + 1)) + 1ULL;
				CharArray i_digits = toCharArray(i_magnitude);

				CharArray i_array;
				i_array.createArrayFast(i_digits.length() + 1);
				i_array.setLength(i_digits.length() + 1);
				i_array.setFast(0, '-');
				for(int x = 0; x < i_digits.length(); x++){
					i_array.setFast(x + 1, i_digits.getFast(x));
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const unsigned int& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const unsigned int&");
				CharArray i_array = toCharArray(static_cast<unsigned long long>(a_value));
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const unsigned long& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const unsigned long&");
				CharArray i_array = toCharArray(static_cast<unsigned long long>(a_value));
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const unsigned short& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const unsigned short&");
				CharArray i_array = toCharArray(static_cast<unsigned long long>(a_value));
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const short& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const short&");
				CharArray i_array = toCharArray(static_cast<int>(a_value));
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(float a_value, int a_decimal_size){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "float, int");

				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "a_value");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", a_value);
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "decimal_size");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", a_decimal_size);
				
				CharArray i_array = toCharArray((int)a_value);
				float i_decimals = pankey::Utility::Test::getDecimals(a_value, a_decimal_size, true);
				i_array.add('.');
				if(i_decimals < 0) i_decimals *= -1;

				int i_exp = 1;
				for(int x = 0; x < a_decimal_size; x++)i_exp *= 10;

				int i_int_D = (i_decimals) * i_exp;
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", "i_int_D");
				CharArrayPrimitiveLog(pankey_Log_Statement, "toCharArray", i_int_D);

				CharArray i_int_S = toCharArray(i_int_D);

				i_array.add(i_int_S);

				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const float& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toCharArray", "const float&");
				CharArray i_array = toCharArray(a_value, 2);
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toCharArray", "");
				return i_array;
			}

			CharArray toCharArray(const char& a_value){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "Constructor", "const char& c_char");
				CharArrayPrimitiveLog(pankey_Log_Statement, "Constructor", "Char:");
				CharArrayPrimitiveLog(pankey_Log_Statement, "Constructor", a_value);
				CharArray i_array;
				i_array.createArrayFast(1);
				i_array.setFast(0, a_value);
				i_array.setLength(1);
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "Constructor", "");
				return i_array;
			}

			char toChar(const CharArray& a_array){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toChar", "const CharArray&");
				if(a_array.length() > 0){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toChar", "");
					return a_array.get(0);
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toChar", "");
				return '\0';
			}

			int toInt(const CharArray& a_array){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toInt", "");
				if(a_array.isEmpty()){
					CharArrayPrimitiveLog(pankey_Log_EndMethod, "toInt", "a_array.isEmpty()");
					return 0;
				}
				int i_start = 0;
				if(a_array.get(0) == '-'){
					i_start = 1;
				}
				int output = 0;
				int c_size = a_array.length();
				bool lastDecimals = false;
				for(int x = i_start; x < c_size; x++){
					char f_char = a_array.get(x);
					CharArrayPrimitiveLog(pankey_Log_StartMethod, "toInt", "f_char");
					CharArrayPrimitiveLog(pankey_Log_StartMethod, "toInt", f_char);
					if(pankey::Utility::Test::isDecimalPoint(f_char)){
						if(lastDecimals){
							CharArrayPrimitiveLog(pankey_Log_EndMethod, "toInt", "allready has a decimal point");
							return 0;
						}
						lastDecimals = true;
						continue;
					}
					if(pankey::Utility::Test::isNumber(f_char)){
						if(lastDecimals){
							
						}else{
							CharArrayPrimitiveLog(pankey_Log_Statement, "toInt", "int part");
							if(x != i_start){
								output *= 10;
							}
							output += (f_char - 48);
							CharArrayPrimitiveLog(pankey_Log_Statement, "toInt", "output");
							CharArrayPrimitiveLog(pankey_Log_Statement, "toInt", output);
						}
					}else{
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toInt", "");
						return 0;
					}
				}
				if(i_start == 1){
					output *= -1;
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toInt", "");
				return output;
			}

			bool toBool(const CharArray& a_array){
				CharArrayPrimitiveLog(pankey_Log_StartMethod, "toBool", "const CharArray&");
				if(a_array.length() == 1){
					if(a_array.get(0) == '1'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "1");
						return true;
					}
					if(a_array.get(0) == '0'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "0");
						return false;
					}
				}
				if(a_array.length() == 4){
					if(a_array.get(0) == 't' && a_array.get(1) == 'r' && a_array.get(2) == 'u' && a_array.get(3) == 'e'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "true");
						return true;
					}
					if(a_array.get(0) == 'T' && a_array.get(1) == 'R' && a_array.get(2) == 'U' && a_array.get(3) == 'E'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "TRUE");
						return true;
					}
				}
				if(a_array.length() == 5){
					if(a_array.get(0) == 'f' && a_array.get(1) == 'a' && a_array.get(2) == 'l' && a_array.get(3) == 's' && a_array.get(4) == 'e'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "false");
						return false;
					}
					if(a_array.get(0) == 'F' && a_array.get(1) == 'A' && a_array.get(2) == 'L' && a_array.get(3) == 'S' && a_array.get(4) == 'E'){
						CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "False");
						return false;
					}
				}
				CharArrayPrimitiveLog(pankey_Log_EndMethod, "toBool", "Not bool");
				return false;
			}

		}
		
	}
		
}