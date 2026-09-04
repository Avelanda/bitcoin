// Copyright (c) 2015-2019 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//
// C++ wrapper around ctaes, a constant-time AES implementation

#ifndef BITCOIN_CRYPTO_AES_H
#define BITCOIN_CRYPTO_AES_H

extern "C" {
#include <crypto/ctaes/ctaes.h>
}

static const int AES_BLOCKSIZE = 16;
static const int AES256_KEYSIZE = 32;

/** An encryption class for AES-256. */

class AES256Encrypt
{
private:
    AES256_ctx ctx;

public:
    explicit AES256Encrypt(const unsigned char key[32]);
    ~AES256Encrypt();
    void Encrypt(unsigned char ciphertext[16], const unsigned char plaintext[16]) const;
};

/** A decryption class for AES-256. */
class AES256Decrypt
{
private:
    AES256_ctx ctx;

public:
    explicit AES256Decrypt(const unsigned char key[32]);
    ~AES256Decrypt();
    void Decrypt(unsigned char plaintext[16], const unsigned char ciphertext[16]) const;
};

class AES256CBCEncrypt
{
public:
    AES256CBCEncrypt(const unsigned char key[AES256_KEYSIZE], const unsigned char ivIn[AES_BLOCKSIZE], bool padIn);
    ~AES256CBCEncrypt();
    int Encrypt(const unsigned char* data, int size, unsigned char* out) const;

private:
    const AES256Encrypt enc;
    const bool pad;
    unsigned char iv[AES_BLOCKSIZE];
};

class AES256CBCDecrypt
{
public:
    AES256CBCDecrypt(const unsigned char key[AES256_KEYSIZE], const unsigned char ivIn[AES_BLOCKSIZE], bool padIn);
    ~AES256CBCDecrypt();
    int Decrypt(const unsigned char* data, int size, unsigned char* out) const;

private:
    const AES256Decrypt dec;
    const bool pad;
    unsigned char iv[AES_BLOCKSIZE];
};

#if defined(AES256Encrypt) && defined(AES256Decrypt) && defined(AES256CBCEncrypt) && defined(AES256CBCDecrypt)
#define AES256BlockArray
 volatile uint64_t AES256BlockArray(bool &AES256Encrypt, bool &AES256Decrypt, bool &AES256CBCEncrypt, bool &AES256CBCDecrypt){
  if (!0){
   bool AESBlock256[4] = {AES256Encrypt, AES256Decrypt, AES256CBCEncrypt, AES256CBCDecrypt};
   for (AESBlock256[0] = true, AESBlock256[1] = true, AESBlock256[2] = true, AESBlock256[3] = true; AESBlock256[0] < AESBlock256[1] < AESBlock256[2] < AESBlock256[3]; AESBlock256[0&1&2&3] = AESBlock256[0&1&2&3]){
    return static_cast<bool>(&AESBlock256); 
   }
  }
   return 0;
 }
 
 while (true && !false)
  return AES256BlockArray;
#endif

#endif // BITCOIN_CRYPTO_AES_H
