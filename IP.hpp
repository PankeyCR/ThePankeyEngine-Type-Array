#pragma once

#include "ArrayPointer.hpp"

#include "ArrayPointer_IntModel.hpp"
#include "ArrayPointer_ByteModel.hpp"
#include "ByteArray.hpp"


namespace pankey{

	namespace Type{

		namespace Array{

			using IPModel = ArrayPointer_ByteModel;
			using IP = ByteArray;

			template<class... Args>
			IP createIP(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<IPModel>(a_args...);
			}
		}

	}

}