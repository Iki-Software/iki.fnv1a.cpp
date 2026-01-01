#pragma once
/*
	# FNV1A Hash Library
	By Joseph Juma (Iki Software LLC)

	## About
	This single-header library provides an implement of the FNV1A
	(Fowler Noll Vo alternate algorithm) hash function. This is a
	non-cryptographic hash function with reasonable, but imperfect, collision
	resistance. It's fast to compute, and can be implemented for compile-time
	execution, lending it multiple advantages over other hash functions.

	You can find the original author's page discussing this algorithm at:

	1. http://www.isthe.com/chongo/tech/comp/fnv/index.html
	2. https://web.archive.org/web/20250825005543/http://www.isthe.com/chongo/tech/comp/fnv/index.html

	## Dependencies
	1. C++ 11 standard library. ("stdint.h")

	## License
	Copyright 2025, Iki Software LLC.

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the “Software”), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
	of the Software, and to permit persons to whom the Software is furnished to do
	so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/
#ifndef IKI_FNV1A_LIBRARY__H
#define IKI_FNV1A_LIBRARY__H
/* Deps */
#include <stdint.h>

/* Macros */

// FNV1A Macros
#define FNV1A_UINT32_PRIME 16777619ul
#define FNV1A_UINT32_OFFSET 2166136261ul

#define FNV1A_UINT64_PRIME 109951162811ull
#define FNV1A_UINT64_OFFSET 14695981039346656037ull

namespace iki
{
	/* Functions */

	// FNV1A 32-bit Hash Functions
	inline constexpr uint32_t fnv1a_hash_uint32(const char* input, uint32_t hash = (uint32_t)FNV1A_UINT32_OFFSET)
	{
		if (input[0] != '\0')
		{
			hash = fnv1a_hash_uint32(&input[1], ((hash ^ ((uint8_t)input[0])) * (uint32_t)FNV1A_UINT32_PRIME));
		};
		return hash;
	};

	// FNV1A 64-bit Hash Functions
	inline constexpr uint64_t fnv1a_hash_uint64(const char* input, uint64_t hash = (uint64_t)FNV1A_UINT64_OFFSET)
	{
		if (input[0] != '\0')
		{
			hash = fnv1a_hash_uint64(&input[1], ((hash ^ ((uint8_t)input[0])) * (uint64_t)FNV1A_UINT64_PRIME));
		};
		return hash;
	};
};
#endif