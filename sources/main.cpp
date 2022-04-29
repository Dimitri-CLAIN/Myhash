#include <stdexcept>
#include <iostream>

#include <helpers.hpp>
#include <hash-function.hpp>

hash_uint_t my_hash(const hash_key & hk)
 {
  const unsigned char * s = hk.first;
  size_t l = hk.second;
  hash_uint_t h = 0;

  for (size_t i = 0; i < l; i++)
    h = helpers::ror(h, 5) ^ helpers::rol(h, 5) ^ s[i];
  h = helpers::perfect_shuffle(h);
  return h;
 }

////////////////////////////////////////
//
// hash_key.first : pointeur sur les données
// hash_key.second: nombre de bytes
//
hash_uint_t pourrie(const hash_key & hk)
 {
  const unsigned char * s = hk.first;
  size_t l = hk.second;

  hash_uint_t h=0;
  for (size_t i=0;i<l;i++)
   h+=s[i];

  return h;
 }

////////////////////////////////////////
//
// montre l'utilisation des helpers
//
hash_uint_t moins_pourrie(const hash_key & hk)
 {
  const unsigned char * s = hk.first;
  size_t l = hk.second;

  hash_uint_t h=0;
  for (size_t i=0;i<l;i++)
   {
    h+=s[i]*helpers::magie_1;
    h=helpers::perfect_shuffle(h);
   }

  return h;
 }

////////////////////////////////////////
int main(int argc, char * argv[])
 {
  if (argc>1)
   {
    size_t  nb_bins=10;
    try {
     nb_bins=std::stol(argv[1]);
    }
    catch (std::exception & e)
     {
      std::cerr << "paramètre invalide!" << std::endl;
      return 2; // deuxieme erreur
     }

    // crée l'histogramme à zéro partout
    size_t * histo = new size_t[nb_bins]();

    // lis les lignes une par une
    while (std::cin)
     {
      std::string ligne;

      // ici, c'est nécessaire d'avoir une
      // abstraction des données (voir les
      // commentaires dans hash-adapter.hpp)
      //
      if (std::getline(std::cin,ligne))
       histo[ my_hash(hash_key_adapter<std::string>::adapter(ligne)) % nb_bins ]++;
     }

    // produit l'histogramme
    for (size_t i=0;i<nb_bins;i++)
     std::cout << i << '\t' << histo[i] << std::endl;

    // ménage
    delete[] histo;
   }
  else
   {
    std::cerr
     << "Veuillez spécifier le nombre de cases de l'histogramme (1-.... )" << std::endl;
    return 1; // erreur quelconque
   }

  return 0;
 }
