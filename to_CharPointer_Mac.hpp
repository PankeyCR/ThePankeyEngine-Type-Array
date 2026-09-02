#pragma once

	#include "CharPointer.hpp"
	#include "to_Primitive_CharPointer.hpp"
	#include "Mac.hpp"
	#include "to_CharArray_CharPointer.hpp"
	#include "ArrayPointerHelper.hpp"

	#if defined(pankey_Log) && (defined(to_CharPointer_Mac_Log) || defined(pankey_Global_Log) || defined(pankey_Arduino_Log))
		#include "Logger_status.hpp"
		#define to_CharPointer_MacLog(status,method,mns) pankey_Log(status,"to_CharPointer_Mac",method,mns)
	#else
		#define to_CharPointer_MacLog(status,method,mns)
	#endif

	namespace pankey{

		namespace Type{

			namespace Array{

				CharPointer toCharPointerFromMac(const Mac& a_array){
					to_CharPointer_MacLog(pankey_Log_StartMethod, "toCharPointerFromMac", "");
					if(a_array.isEmpty()){
						to_CharPointer_MacLog(pankey_Log_EndMethod, "toCharPointerFromMac", "a_array.isEmpty()");
						return CharPointer();
					}
					to_CharPointer_MacLog(pankey_Log_Statement, "toCharPointerFromMac", "length:");
					to_CharPointer_MacLog(pankey_Log_Statement, "toCharPointerFromMac", a_array.length());
					
					pankey::Utility::Test::CharPointer i_mac_1 = pankey::Utility::Test::toCharPointer((int)a_array.get(0));
					pankey::Utility::Test::CharPointer i_mac_2 = pankey::Utility::Test::toCharPointer((int)a_array.get(1));
					pankey::Utility::Test::CharPointer i_mac_3 = pankey::Utility::Test::toCharPointer((int)a_array.get(2));
					pankey::Utility::Test::CharPointer i_mac_4 = pankey::Utility::Test::toCharPointer((int)a_array.get(3));
					pankey::Utility::Test::CharPointer i_mac_5 = pankey::Utility::Test::toCharPointer((int)a_array.get(4));
					pankey::Utility::Test::CharPointer i_mac_6 = pankey::Utility::Test::toCharPointer((int)a_array.get(5));

					pankey::Utility::Test::CharPointer i_array;
					i_array.create(	i_mac_1.length() + 
									i_mac_2.length() + 
									i_mac_3.length() + 
									i_mac_4.length() + 
									i_mac_5.length() + 
									i_mac_6.length() + 
									5
								);
					i_array.set(	0, 							i_mac_1);

					i_array.set(	i_mac_1.length() + 1, 		i_mac_2);

					i_array.set(	i_mac_1.length() + 
									i_mac_2.length() + 2, 		i_mac_3);

					i_array.set(	i_mac_1.length() + 
									i_mac_2.length() + 
									i_mac_3.length() + 3, 		i_mac_4);

					i_array.set(	i_mac_1.length() + 
									i_mac_2.length() + 
									i_mac_3.length() + 
									i_mac_4.length() + 4, 		i_mac_5);

					i_array.set(	i_mac_1.length() + 
									i_mac_2.length() + 
									i_mac_3.length() + 
									i_mac_4.length() + 
									i_mac_5.length() + 5, 		i_mac_6);
					to_CharPointer_MacLog(pankey_Log_EndMethod, "toCharPointerFromMac", "");
					return i_array;
				}

				Mac toMAC(const pankey::Utility::Test::CharPointer& a_mac){
					CharArray i_array = toCharArray(a_mac);
					auto i_split = pankey::DataStructure::Array::split(i_array, '.');
					Mac i_mac;
					if(i_split.length() != 6){
						return i_mac;
					}
					i_mac.add(toInt(i_split.get(0)));
					i_mac.add(toInt(i_split.get(1)));
					i_mac.add(toInt(i_split.get(2)));
					i_mac.add(toInt(i_split.get(3)));
					i_mac.add(toInt(i_split.get(4)));
					i_mac.add(toInt(i_split.get(5)));
					return i_mac;
				}
				
			}
			
		}
			
	}