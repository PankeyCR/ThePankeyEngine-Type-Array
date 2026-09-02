#pragma once

#include "ArrayPointer_FloatModel.hpp"
#include "ArrayPointer_IntModel.hpp"
#include "DimensionalArray.hpp"
#include "FloatArray.hpp"
#include "IntegerArray.hpp"

namespace pankey{

    namespace Type{

        namespace Array{

            using Tensor = pankey::DataStructure::Array::DimensionalArray<
                pankey::Type::Array::ArrayPointer_FloatModel,
                pankey::Type::Array::ArrayPointer_IntModel
            >;

        }

    }

}
