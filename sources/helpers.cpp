#include <helpers.hpp>

namespace helpers {

 // abcdefgh -> hgfedcba
 uint64_t reverse(uint64_t x)
 {
  x= (x << 32) | (x>>32);
  x= ((x & 0xffff0000ffff0000) >> 16) |
     ((x & 0x0000ffff0000ffff) << 16) ;

  x= ((x & 0xff00ff00ff00ff00) >> 8) |
     ((x & 0x00ff00ff00ff00ff) << 8) ;

  x= ((x & 0xf0f0f0f0f0f0f0f0) >> 4) |
     ((x & 0x0f0f0f0f0f0f0f0f) << 4) ;

  x= ((x & 0xcccccccccccccccc) >> 2) |
     ((x & 0x3333333333333333) << 2) ;

  x= ((x & 0xaaaaaaaaaaaaaaaa) >> 1) |
     ((x & 0x5555555555555555) << 1);

  return x;
 }


 // abcdefgh -> aebfcgdh
 uint64_t perfect_shuffle(uint64_t x)
  {
   x= ((x & 0xffff00000000ffff)) |
      ((x & 0x0000ffff00000000) >> 16) |
      ((x & 0x00000000ffff0000) << 16) ;

   x= ((x & 0xff0000ffff0000ff)) |
      ((x & 0x00ff000000ff0000) >> 8) |
      ((x & 0x0000ff000000ff00) << 8) ;

   x= ((x & 0xf00ff00ff00ff00f)) |
      ((x & 0x0f000f000f000f00) >> 4) |
      ((x & 0x00f000f000f000f0) << 4) ;

   x= ((x & 0xc3c3c3c3c3c3c3c3)) |
      ((x & 0x3030303030303030) >> 2) |
      ((x & 0x0c0c0c0c0c0c0c0c) << 2) ;

   x= ((x & 0x9999999999999999)) |
      ((x & 0x4444444444444444) >> 1) |
      ((x & 0x2222222222222222) << 1) ;

   return x;
  }

} // namespace bit_helpers
