#pragma once

	#include "CharPointer.hpp"
	#include "to_Primitive_CharPointer.hpp"
	#include "IP.hpp"
	#include "to_CharArray_CharPointer.hpp"
	#include "ArrayPointerHelper.hpp"
	#include "CharArrayPrimitive.hpp"

	#if defined(pankey_Log) && (defined(to_CharPointer_IP_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
		#include "Logger_status.hpp"
		#define to_CharPointer_IPLog(status,method,mns) pankey_Log(status,"to_CharPointer_IP",method,mns)
	#else
		#define to_CharPointer_IPLog(status,method,mns)
	#endif

	namespace pankey{

		namespace Type{

			namespace Array{

				CharPointer toCharPointerFromIp(const IP& a_array){
					to_CharPointer_IPLog(pankey_Log_StartMethod, "toCharPointerFromIp", "");
					if(a_array.isEmpty()){
						to_CharPointer_IPLog(pankey_Log_EndMethod, "toCharPointerFromIp", "a_array.isEmpty()");
						return CharPointer();
					}
					to_CharPointer_IPLog(pankey_Log_Statement, "toCharPointerFromIp", "length:");
					to_CharPointer_IPLog(pankey_Log_Statement, "toCharPointerFromIp", a_array.length());
					
					CharPointer i_ip_1 = pankey::Utility::Test::toCharPointer((int)a_array.get(0));
					CharPointer i_ip_2 = pankey::Utility::Test::toCharPointer((int)a_array.get(1));
					CharPointer i_ip_3 = pankey::Utility::Test::toCharPointer((int)a_array.get(2));
					CharPointer i_ip_4 = pankey::Utility::Test::toCharPointer((int)a_array.get(3));

					CharPointer i_array;
					i_array.create(	i_ip_1.length() + 
									i_ip_2.length() + 
									i_ip_3.length() + 
									i_ip_4.length() + 
									3
								);
					i_array.set(	0, 							i_ip_1);

					i_array.set(	i_ip_1.length() + 1, 		i_ip_2);

					i_array.set(	i_ip_1.length() + 
									i_ip_2.length() + 2, 		i_ip_3);

					i_array.set(	i_ip_1.length() + 
									i_ip_2.length() + 
									i_ip_3.length() + 3, 		i_ip_4);

					to_CharPointer_IPLog(pankey_Log_EndMethod, "toCharPointerFromIp", "");
					return i_array;
				}

				IP toIP(const CharPointer& a_ip){
					CharArray i_array = toCharArray(a_ip);
					auto i_split = pankey::DataStructure::Array::split(i_array, '.');
					IP i_ip;
					if(i_split.length() != 4){
						return i_ip;
					}
					i_ip.add(pankey::Type::Array::toInt(i_split.get(0)));
					i_ip.add(pankey::Type::Array::toInt(i_split.get(1)));
					i_ip.add(pankey::Type::Array::toInt(i_split.get(2)));
					i_ip.add(pankey::Type::Array::toInt(i_split.get(3)));
					return i_ip;
				}
				
			}
			
		}
			
	}