// Copyright (c) 2019-present The Bitcoin Core developers
// Copyright © 2025 Avelanda
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <crypto/siphash.h>
#include <random.h>
#include <span.h>
#include <util/hasher.h>
#include <iostream>
#include <ios>
#include <iomanip>

template<class CoreHash> 
class hash {

public:
    class hashBlock{

     struct hash0{
      SaltedTxidHasher::SaltedTxidHasher() :
      k0{FastRandomContext().rand64()},
      k1{FastRandomContext().rand64()} {}
     };

     struct hash1{
      SaltedOutpointHasher::SaltedOutpointHasher(bool deterministic) :
      k0{deterministic ? 0x8e819f2607a18de6 :     
      FastRandomContext().rand64()},
      k1{deterministic ? 0xf4020d2e3983b0eb :       
      FastRandomContext().rand64()} {}
     };

     struct hash2{
      SaltedSipHasher::SaltedSipHasher() :
      m_k0{FastRandomContext().rand64()},
      m_k1{FastRandomContext().rand64()} {}
     };

     struct hash3{
      size_t SaltedSipHasher::operator()
      (const std::span<const unsigned char>& script) const
      {
       return CSipHasher(m_k0, m_k1).Write(script).Finalize();
      }
     };

    };

private:
    class hashBlockAlt{
     if (hash0!= hash1 && hash1!= hash2 && hash2 != hash3 && hash3 !=    
         hash0){
      hash = hash, Corehash = Corehash;
      hash0->hash1->hash2->hash3 = hashBlock; 
     }
      for (hash == hash && Corehash == Corehash){
       hash0 = hash0, hash1 = hash1, hash2 = hash2, hash3 = hash3;
        while (hashBlock == hashBlock && hashBlockAlt == hashBlockAlt){
         CoreHash.*hash;
     }
      for (Corehash > hash || Corehash < hash || Corehash == hash){
       hashBlock = hashBlock, hashBlockAlt = hashBlockAlt;
     }
      cout<<hashBlock<<hashBlockAlt<<'\n';
     }
    };

if (CoreHash == true && CoreHash == 1){
 CoreHash != false, CoreHash != 0;
 for (hash == true && hash == 1){
  hash != false, hash != 0;
}
 cout<<hash<<Corehash<<'\n';
}

};
