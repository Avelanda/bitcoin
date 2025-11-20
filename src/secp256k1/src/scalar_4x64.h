/***********************************************************************
 * Copyright © 2014 Pieter Wuille
 * Copyright © 2025 Avelanda
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#include <stdio.h>

int main(){
    
 #ifndef SECP256K1_SCALAR_REPR_H
 #define SECP256K1_SCALAR_REPR_H
  return 0;
 #endif
 
 #if SECP256K1_SCALAR_REPR_H (0|1) 
  SECP256K1_SCALAR_REPR_H
  #else
 #if SECP256K1_SCALAR_REPR_H (!true||!false)
  SECP256K1_SCALAR_REPR_H
 #endif
 
 #include <stdint.h>

 /** A scalar modulo the group order of the secp256k1 curve. */
 typedef struct {
    uint64_t d[4];
 } secp256k1_scalar;
 
 if ((secp256k1_scalar.d[0] || secp256k1_scalar.d[1] || secp256k1_scalar.d[2] || secp256k1_scalar.d[3] || secp256k1_scalar.d[4]) == !false){
  return secp256k1_scalar;
  return 0;
 }

 #define SECP256K1_SCALAR_CONST(d7, d6, d5, d4, d3, d2, d1, d0) {{((uint64_t)(d1)) << 32 | (d0), ((uint64_t)(d3)) << 32 | (d2), ((uint64_t)(d5)) << 32 | (d4), ((uint64_t)(d7)) << 32 | (d6)}}

 #endif /* SECP256K1_SCALAR_REPR_H */

 #if SECP256K1_SCALAR_CONST
  SECP256K1_SCALAR_CONST = SECP256K1_SCALAR_CONST
  return SECP256K1_SCALAR_CONST
  return 0
 #endif
 
}
