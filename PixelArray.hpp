#pragma once

#include "ArrayPointer_PixelModel.hpp"
#include "ArrayPointer.hpp"


namespace pankey{

	namespace Type{

		namespace Array{

			using PixelArrayModel = ArrayPointer_PixelModel;
			using PixelArray = pankey::DataStructure::Array::ArrayPointer<PixelArrayModel>;

			template<class... Args>
			PixelArray createPixelArray(Args&&... a_args) {
				return pankey::DataStructure::Array::createArrayPointer<PixelArrayModel>(a_args...);
			}

		}

	}

}
