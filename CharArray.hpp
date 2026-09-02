#pragma once

#include "ArrayPointer_CharModel.hpp"
#include "ArrayPointer.hpp"


namespace pankey{

	namespace Type{

		namespace Array{

			using CharArrayModel = ArrayPointer_CharModel;
			using CharArray = pankey::DataStructure::Array::ArrayPointer<CharArrayModel>;

			template<class... Args>
			CharArray createCharArray(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<CharArrayModel>(a_args...);
			}

		}

	}

}