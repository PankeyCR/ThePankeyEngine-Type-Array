#pragma once

#include "ArrayPointer_FloatModel.hpp"
#include "ArrayPointer.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			using FloatArrayModel = ArrayPointer_FloatModel;
			using FloatArray = pankey::DataStructure::Array::ArrayPointer<FloatArrayModel>;

			template<class... Args>
			FloatArray createFloatArray(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<FloatArrayModel>(a_args...);
			}
			
		}
		
	}
}
