#pragma once

#include "MemoryAllocator.hpp"
#include "Byte.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			struct ArrayPointer_ByteModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = Byte;
				using SIZE_TYPE = Byte;
			};

		}

	}

}



