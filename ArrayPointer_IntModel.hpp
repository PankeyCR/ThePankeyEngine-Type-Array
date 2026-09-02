#pragma once

#include "MemoryAllocator.hpp"
#include "Byte.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			struct ArrayPointer_IntModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = int;
				using SIZE_TYPE = int;
			};

		}

	}

}



