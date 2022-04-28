#ifndef __MODULE_HASH_FUNCTION__
#define __MODULE_HASH_FUNCTION__

#include <cstddef>
#include <cstdint>

#include <hash-adapter.hpp>

using hash_uint_t=uint64_t;
using hash_function_t = hash_uint_t (*)(const char[], size_t);

#endif
 // __MODULE_HASH_FUNCTION__
