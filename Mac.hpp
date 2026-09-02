#pragma once

#include "ArrayPointer.hpp"

#include "ArrayPointer_IntModel.hpp"
#include "ArrayPointer_ByteModel.hpp"
#include "ByteArray.hpp"


namespace pankey{

	namespace Type{

		namespace Array{

			using MacModel = ArrayPointer_ByteModel;
			using Mac = ByteArray;

			template<class... Args>
			Mac createMac(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<MacModel>(a_args...);
			}

		}

	}

}