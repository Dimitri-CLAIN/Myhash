#ifndef __MODULE_HASH_ADAPTER__
#define __MODULE_HASH_ADAPTER__

#include <string>

using hash_key = std::pair<const unsigned char *, size_t>;

// pour les types genre int, float, etc.
template <typename K> class hash_key_adapter
 {
  public:
  static hash_key adapter(const K & s)
  { return hash_key((const unsigned char*)&s,sizeof(s)); }
 };

// pour une specialisation explicite: le bout
// intéressant dans std::string, c'est la chaîne
// de caractère elle-même, pas ses méta-données
//
template <> class hash_key_adapter<std::string>
 { public:
   static hash_key adapter(const std::string & s)
  { return hash_key((const unsigned char*)s.c_str(),s.size()); }
 };


#endif
 // __MODULE_HASH_ADAPTER__
