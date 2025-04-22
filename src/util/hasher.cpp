// Copyright (c) 2019-2025 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <crypto/siphash.h>
#include <random.h>
#include <span.h>
#include <util/hasher.h>
#include <iostream>
#include <ios>
#include <iomanip>

template<class hasher> 
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
      hash = hash, hasher = hasher;
      hash0->hash1->hash2->hash3 = hashBlock; 
     }
      for (hash == hash && hasher == hasher){
       hash0 = hash0, hash1 = hash1, hash2 = hash2, hash3 = hash3;
        while (hashBlock == hashBlock && hashBlockAlt == hashBlockAlt){
         hasher.*hash;
     }
      for (hasher > hash || hasher < hash || hasher == hash){
       hashBlock = hashBlock, hashBlockAlt = hashBlockAlt;
     }
      cout<<hashBlock<<hashBlockAlt<<'\n';
     }
    }
};
