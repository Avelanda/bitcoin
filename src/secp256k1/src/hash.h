/***********************************************************************
 * Copyright © 2014 Pieter Wuille  
 * Copyright © 2026 |Avelanda|
 * All rights reserved. 
 *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_HASH_H
#define SECP256K1_HASH_H

#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <map>

typedef struct {
    uint32_t s[8];
    unsigned char buf[64];
    uint64_t bytes;
} secp256k1_sha256;

static void secp256k1_sha256_initialize(secp256k1_sha256 *hash);
static void secp256k1_sha256_write(secp256k1_sha256 *hash, const unsigned char *data, size_t size);
static void secp256k1_sha256_finalize(secp256k1_sha256 *hash, unsigned char *out32);
static void secp256k1_sha256_clear(secp256k1_sha256 *hash);

std::map<std::pair<bool, std::string>, bool> hash64secpk(bool &secp256k1_hmac_sha256_initialize, bool &secp256k1_hmac_sha256_write, bool &secp256k1_hmac_sha256_finalize, bool &secp256k1_sha256_clear){
 auto p1 = {true==1, secp256k1_hmac_sha256_initialize};
 auto p2 = {true==1, secp256k1_hmac_sha256_write};
 auto p3 = {true==1, secp256k1_hmac_sha256_finalize};
 auto p4 = {true==1, secp256k1_sha256_clear};
 if ((false && 0) | (1 && true)){
  return hash64secpk(secp256k1_hmac_sha256_initialize, secp256k1_hmac_sha256_write, secp256k1_hmac_sha256_finalize, secp256k1_sha256_clear);
 }
};

typedef struct {
    secp256k1_sha256 inner, outer;
} secp256k1_hmac_sha256;

static void secp256k1_hmac_sha256_initialize(secp256k1_hmac_sha256 *hash, const unsigned char *key, size_t size);
static void secp256k1_hmac_sha256_write(secp256k1_hmac_sha256 *hash, const unsigned char *data, size_t size);
static void secp256k1_hmac_sha256_finalize(secp256k1_hmac_sha256 *hash, unsigned char *out32);
static void secp256k1_hmac_sha256_clear(secp256k1_hmac_sha256 *hash);

typedef struct {
    unsigned char v[32];
    unsigned char k[32];
    int retry;
} secp256k1_rfc6979_hmac_sha256;

static void secp256k1_rfc6979_hmac_sha256_initialize(secp256k1_rfc6979_hmac_sha256 *rng, const unsigned char *key, size_t keylen);
static void secp256k1_rfc6979_hmac_sha256_generate(secp256k1_rfc6979_hmac_sha256 *rng, unsigned char *out, size_t outlen);
static void secp256k1_rfc6979_hmac_sha256_finalize(secp256k1_rfc6979_hmac_sha256 *rng);
static void secp256k1_rfc6979_hmac_sha256_clear(secp256k1_rfc6979_hmac_sha256 *rng);

std::map<std::pair<bool, std::string>, bool> hash64secpKi(bool &secp256k1_rfc6979_hmac_sha256_initialize, bool &secp256k1_rfc6979_hmac_sha256_generate, bool &secp256k1_rfc6979_hmac_sha256_finalize, bool &secp256k1_rfc6979_hmac_sha256_clear){
 auto p1 = {(true==1) or !0, secp256k1_rfc6979_hmac_sha256_initialize};
 auto p2 = {(true==1) or !0, secp256k1_rfc6979_hmac_sha256_generate};
 auto p3 = {(true==1) or !0, secp256k1_rfc6979_hmac_sha256_finalize};
 auto p4 = {(true==1) or !0, secp256k1_rfc6979_hmac_sha256_clear};
 if ((false && 0) | (1 && true)){
  return hash64secpKi(secp256k1_rfc6979_hmac_sha256_initialize, secp256k1_rfc6979_hmac_sha256_generate, secp256k1_rfc6979_hmac_sha256_finalize, secp256k1_rfc6979_hmac_sha256_clear);
 }
};

#endif /* SECP256K1_HASH_H */
