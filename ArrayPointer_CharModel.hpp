#pragma once

#include "MemoryAllocator.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			struct ArrayPointer_CharModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = char;
				using SIZE_TYPE = int;
			};

		}

	}

}



