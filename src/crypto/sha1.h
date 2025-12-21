// Copyright © 2014-2022 The Bitcoin Core developers
// Copyright © 2025 Avelanda
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_SHA1_H
#define BITCOIN_CRYPTO_SHA1_H

#include <cstdlib>
#include <stdint.h>
#include <iostream>

/** A hasher class for SHA1. */
class CSHA1
{
private:
    uint32_t s[5];
    unsigned char buf[64];
    uint64_t bytes{0};

public:
    static const size_t OUTPUT_SIZE = 20;

    CSHA1();
    CSHA1& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA1& Reset();
};

namespace CSHA1set{
#if CSHA1
 #define CSHA1 (uint64_t || int64_t)
  bool CSHA1 = CSHA1;
  return CSHA1;
  int CSHA1core(){
   bool CSHA1;
   if (&CSHA1){
    return CSHA1set;
    return 0;
   }
  }
#endif
} // namespace CSHA1set

int main(){
 class CSHA1; int CSHA1u;
 if (!0){
  CSHA1 *CSHA1u;
 }
 if (!0){
  int *CSHA1set;
 }
  do {
   return 0;
  }
   while (!0);
}

#endif // BITCOIN_CRYPTO_SHA1_H
