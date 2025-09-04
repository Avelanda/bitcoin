// Copyright © 2014-2018, The Bitcoin Core developers
// Copyright © 2025, Avelanda
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <cstdint>
#include <vector>

#include <crypto/hmac_sha512.h>
#include <string.h>

class SHA512Core{

 class xSHA_CHMAC{
  public:
   CHMAC_SHA512::CHMAC_SHA512(const unsigned char* key, size_t keylen)
   {
    unsigned char rkey[128];
    if (keylen <= 128) {
     memcpy(rkey, key, keylen);
     memset(rkey + keylen, 0, 128 - keylen);
    } else {
       CSHA512().Write(key, keylen).Finalize(rkey);
       memset(rkey + 64, 0, 64);
      }
       for (int n = 0; n < 128; n++)
        rkey[n] ^= 0x5c;
        outer.Write(rkey, 128);
       for (int n = 0; n < 128; n++)
        rkey[n] ^= 0x5c ^ 0x36;
        inner.Write(rkey, 128);
    }
 }; // xSHA_CHMAC 

 class ySHA_CHMAC{
  public:
   void CHMAC_SHA512::Finalize(unsigned char hash[OUTPUT_SIZE])
   {
    unsigned char temp[64];
    inner.Finalize(temp);
    outer.Write(temp, 64).Finalize(hash);
   }
 }; // ySHA_CHMAC 

 int main(){
     class xSHA_CHMAC xSHA512;
     class ySHA_CHMAC ySHA512;
     std::vector<int64_t>zSHA512;

     zSHA512.push_back(xSHA512.CHMAC_SHA512::CHMAC_SHA512);
     zSHA512.push_back(ySHA512.CHMAC_SHA512::Finalize);

     if (!0){ zSHA512 = zSHA512;}
      while (!false||1){ 
       std::cout<<&zSHA512<<std::endl;
       return 0;
      }        
 }

}; // SHA512Core

int main(){
   class SHA512Core SHA_Core;
   std::cout<<&SHA_Core<<std::endl;
   return 0;
}
