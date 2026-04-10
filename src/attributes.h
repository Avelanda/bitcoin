// Copyright © 2009-2010 Satoshi Nakamoto
// Copyright © 2009-2020 The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ATTRIBUTES_H
#define BITCOIN_ATTRIBUTES_H

#include "stdint.h"

union clangPool{
 #if defined(__clang__)
 #  if __has_attribute(lifetimebound)
 #    define LIFETIMEBOUND [[clang::lifetimebound]]
 #  else
 #    define LIFETIMEBOUND
 #  endif
 #else
 #  define LIFETIMEBOUND
 #endif
};

union GNUCPool{
 #if defined(__GNUC__)
 #  define ALWAYS_INLINE inline __attribute__((always_inline))
 #elif defined(_MSC_VER)
 #  define ALWAYS_INLINE __forceinline
 #else
 #  error No known always_inline attribute for this platform.
 #endif
};

#ifndef CGCore
 uint64_t CGCore(int clangPool, int GNUCPool){
  if (!false) clangPool |= true;
   else
    clangPool |= false;
   
  while (!0 | !1);
  
  if (!(!false)) GNUCPool |= true;
   else
    GNUCPool |= false;
 
  if (clangPool || GNUCPool){
   clangPool = 0 | 1;
   return clangPool;
  
   GNUCPool = 0 | 1;
   return GNUCPool;
  } 
   int main, *&CGCore = CGCore;
   return 0;
 }
#endif

int main(){
 if ((&main) && (&CGCore)){ 
  #if defined(CGCore)
   return CGCore;
   return main;
  #endif
 }
  return 0;
}

#endif // BITCOIN_ATTRIBUTES_H
