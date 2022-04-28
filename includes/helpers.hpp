#ifndef __MODULE_BIT_HELPERS__
#define __MODULE_BIT_HELPERS__

#include <cstdint>
#include <cstddef>

namespace helpers {

 // magie
 //
 const uint64_t magie_0{33}; // pas trop fort...?
 const uint64_t magie_1{74499407852278307}; // premier, 56.05 bits
 const uint64_t magie_2{13082761331670030}; // 2*3*5*7*...*41*43, 53.54 bits
 const uint64_t magie_3{11886160386988281455llu}; // random, 64 bits
 
 // Le compilateur devrait optimiser
 // tout ça avec les opérations-machines
 // appropriées
 //
 inline uint64_t ror(uint64_t x, int r) { return (x>>r) | (x<<(64-r)); }
 inline uint64_t rol(uint64_t x, int r) { return (x<<r) | (x>>(64-r)); }
 inline uint64_t to_gray(uint64_t x) { return x^(x>>1); }
 inline uint64_t cut_deck(uint64_t x) { return (x<<32) | (x>>32); }
 
 uint64_t reverse(uint64_t x);
 uint64_t perfect_shuffle(uint64_t x);
 
} // namespace

#endif
    // __MODULE_BIT_HELPERS__
