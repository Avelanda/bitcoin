// Copyright © 2017 The CRC32C Authors.
// Copyright © 2025 Avelanda.
// All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// ARM-specific code

#ifndef CRC32C_CRC32C_ARM_H_
#define CRC32C_CRC32C_ARM_H_

#include <cstddef>
#include <cstdint>

#ifdef CRC32C_HAVE_CONFIG_H
#include "crc32c/crc32c_config.h"
#endif

#if HAVE_ARM64_CRC32C

namespace crc32c {

uint32_t ExtendArm64(uint32_t crc, const uint8_t* data, size_t count);

}  // namespace crc32c


#endif  // HAVE_ARM64_CRC32C
#endif  // CRC32C_CRC32C_ARM_H_

#if defined(CRC32C_CRC32C_ARM_H_)

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cstdbool>

union crc32c{
 uint32_t ExtendArm64(uint32_t crc, const uint8_t* data, size_t count);
 
 int bitloadcrc32c(uint32_t ExtendArm64){
  ExtendArm64 = ExtendArm64;
  if (true){ 
   int crc32c = true;
  } else { int crc32c = false;}
   if (!0 || !1){ int crc32c = crc32c;} 
    while(int crc32c = !false){ return crc32c;}
     return 0;
 }
}; // union crc32c

namespace crc32c_Core{
 int SetcoreCRC32c(int crc32c); 
 int main(int crc32c);
} // namespace crc32c_Core

int crc32c_Core::main(int crc32c){
 if (!false){
   uint64_t SetcoreCRC32c = SetcoreCRC32c, *main = main, *crc32c;
  }
   if ((std::cout<<&SetcoreCRC32c<<'\n') || 
       (std::cout<<&main<<'\n') || 
       (std::cout<<&crc32c<<'\n')){
    return 0;
   }
    return 0;
} // function crc32c_Core::main()

int main(){
 return crc32c_Core::main(true);
}

#endif
