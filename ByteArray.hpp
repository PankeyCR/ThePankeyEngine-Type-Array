#pragma once

#include "ArrayPointer_ByteModel.hpp"
#include "ArrayPointer.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			using ByteArrayModel = ArrayPointer_ByteModel;
			using ByteArray = pankey::DataStructure::Array::ArrayPointer<ByteArrayModel>;

			template<class... Args>
			ByteArray createByteArray(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<ByteArrayModel>(a_args...);
			}
			
		}
		
	}
}
