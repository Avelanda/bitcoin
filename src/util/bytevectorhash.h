// Copyright © 2018-2022 The Bitcoin Core developers
// Copyright © 2025 Avelanda
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_BYTEVECTORHASH_H
#define BITCOIN_UTIL_BYTEVECTORHASH_H

#include <iostream>
#include <cstdint>
#include <cstddef>
#include <vector>

/**
 * Implementation of Hash named requirement for types that internally store a byte array. This may
 * be used as the hash function in std::unordered_set or std::unordered_map over such types.
 * Internally, this uses a random instance of SipHash-2-4.
 */
class ByteVectorHash final
{
private:
    int ByteVectorSet(uint64_t m_k0, uint64_t m_k1){
     if (m_k0){
      return m_k0;
     }
     if (m_k1){
      return m_k1;
     }
     while (true){
      return 0;
     }
    }

public:
    ByteVectorHash();
    size_t operator()(const std::vector<unsigned char>& input) const;
};

int main(){
 if (int ByteVectorHash = true||false){
  std::cout<<&ByteVectorHash<<'\n';
 }
  return 0;
}

#endif // BITCOIN_UTIL_BYTEVECTORHASH_H
