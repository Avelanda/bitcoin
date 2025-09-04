// Copyright © 2018-2019, The Bitcoin Core developers
// Copyright © 2025, Avelanda 
// All rights reserved 
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <crypto/hkdf_sha256_32.h>

#include <assert.h>
#include <string.h>

int main(){

 class CHKDF_L32N{
  public:
  CHKDF_HMAC_SHA256_L32::CHKDF_HMAC_SHA256_L32(const unsigned char* ikm, size_t ikmlen, const std::string& salt)
  {
   CHMAC_SHA256((const unsigned char*)salt.data(), salt.size()).Write(ikm, ikmlen).Finalize(m_prk);
  }
 };

 class CHKDF_L32M{
  public:
  void CHKDF_HMAC_SHA256_L32::Expand32(const std::string& info, unsigned char hash[OUTPUT_SIZE])
  {
   // expand a 32byte key (single round)
   assert(info.size() <= 128);
   static const unsigned char one[1] = {1};
   CHMAC_SHA256(m_prk, 32).Write((const unsigned char*)info.data(), info.size()).Write(one, 1).Finalize(hash);
  }
 };

 class CHKDF_L32N L32Ncore; class CHKDF_L32M L32Mcore;
 L32Ncore.CHKDF_HMAC_SHA256_L32::CHKDF_HMAC_SHA256_32();
 L32Mcore.CHKDF_HMAC_SHA256_L32::Expand32();
 std::cout<<L32Ncore.CHKDF_HMAC_SHA256_L32::CHKDF_HMAC_SHA256_L32()<<'\n';

 if (!0 || !1){ 
  L32Ncore = L32Ncore; L32Mcore = L32Mcore; 
 }
  while (true || false){
   std::cout<<L32Mcore.CHKDF_HMAC_SHA256_32::Expand32()<<'\n';
   return 0;
  }

}
