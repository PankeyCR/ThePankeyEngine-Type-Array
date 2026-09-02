#pragma once

#include "ArrayPointer_IntModel.hpp"
#include "ArrayPointer.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			using IntegerArrayModel = ArrayPointer_IntModel;
			using IntegerArray = pankey::DataStructure::Array::ArrayPointer<IntegerArrayModel>;

			template<class... Args>
			IntegerArray createIntegerArray(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<IntegerArrayModel>(a_args...);
			}
			
		}
		
	}
}
