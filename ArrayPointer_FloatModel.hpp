#pragma once

#include "MemoryAllocator.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			struct ArrayPointer_FloatModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = float;
				using SIZE_TYPE = int;
			};

		}

	}

}



