#pragma once

#include "MemoryAllocator.hpp"
#include "Byte.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			// Byte storage with an int SIZE_TYPE, so a buffer can exceed the
			// 255 element ceiling that ByteArray imposes on pixel data.
			struct ArrayPointer_PixelModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = Byte;
				using SIZE_TYPE = int;
			};

		}

	}

}
