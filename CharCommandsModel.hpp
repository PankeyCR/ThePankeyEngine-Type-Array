#pragma once

#include "MemoryAllocator.hpp"
#include "CharPointer.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			struct CharCommandsModel{
				using ALLOCATOR_TYPE = pankey::Memory::Allocator::MemoryAllocator;
				using VALUE_TYPE = pankey::Utility::Test::CharPointer;
				using SIZE_TYPE = int;
			};

		}

	}

}



