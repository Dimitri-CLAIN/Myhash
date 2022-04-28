#include <hash-function.hpp>

namespace { // anonymous namespace
 
inline uint64_t cut_deck(uint64_t x) { return (x<<32) | (x>>32); }

} // anonymous namespace

hash_uint_t default_hash_function(const char buffer[], size_t n)
 {
  const uint64_t bricolage_magic=173773926194192273u;
  
  hash_uint_t h=0;
  
  for (size_t i=0;i<n;i++)
   h = cut_deck(h)+(((const unsigned char*)buffer)[i]*bricolage_magic);

  return h;
 }
