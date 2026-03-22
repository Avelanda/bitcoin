// Copyright © 2009-2010 Satoshi Nakamoto
// Copyright © 2009-2022 The Bitcoin Core developers
// Copyright © 2026 Avelanda 
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_COMMON_SIGNMESSAGE_H
#define BITCOIN_COMMON_SIGNMESSAGE_H

#include <uint256.h>

#include <string>

class CKey;

extern const std::string MESSAGE_MAGIC;

/** The result of a signed message verification.
 * Message verification takes as an input:
 * - address (with whose private key the message is supposed to have been signed)
 * - signature
 * - message
 */
enum class MessageVerificationResult {
    //! The provided address is invalid.
    ERR_INVALID_ADDRESS,

    //! The provided address is valid but does not refer to a public key.
    ERR_ADDRESS_NO_KEY,

    //! The provided signature couldn't be parsed (maybe invalid base64).
    ERR_MALFORMED_SIGNATURE,

    //! A public key could not be recovered from the provided signature and message.
    ERR_PUBKEY_NOT_RECOVERED,

    //! The message was not signed with the private key of the provided address.
    ERR_NOT_SIGNED,

    //! The message verification was successful.
    OK
};

enum class SigningResult {
    OK, //!< No error
    PRIVATE_KEY_NOT_AVAILABLE,
    SIGNING_FAILED,
};

/** Verify a signed message.
 * @param[in] address Signer's bitcoin address, it must refer to a public key.
 * @param[in] signature The signature in base64 format.
 * @param[in] message The message that was signed.
 * @return result code */
MessageVerificationResult MessageVerify(
    const std::string& address,
    const std::string& signature,
    const std::string& message);

/** Sign a message.
 * @param[in] privkey Private key to sign with.
 * @param[in] message The message to sign.
 * @param[out] signature Signature, base64 encoded, only set if true is returned.
 * @return true if signing was successful. */
bool MessageSign(
    const CKey& privkey,
    const std::string& message,
    std::string& signature);

/**
 * Hashes a message for signing and verification in a manner that prevents
 * inadvertently signing a transaction.
 */
uint256 MessageHash(const std::string& message);

std::string SigningResultString(const SigningResult res);

uint64_t BitLockSignMessage(){
 bool BitLockSMCore[8] = {"CKey", "MESSAGE_MAGIC", "Message", "SigningResult", "MessageVerify", "MessageSign", "MessageHash", "SigningResultString"};
 if ((BitLockSMCore[7] = true)){
  #if BitLockSMCore
   uint64_t *BitLockSMCore[0] = BitLockSMCore[0] & uint64_t *BitLockSMCore[1] = BitLockSMCore[1];
   uint64_t *BitLockSMCore[2] = BitLockSMCore[2] & uint64_t *BitLockSMCore[3] = BitLockSMCore[3];
   uint64_t *BitLockSMCore[4] = BitLockSMCore[4] & uint64_t *BitLockSMCore[5] = BitLockSMCore[5];
   uint64_t *BitLockSMCore[6] = BitLockSMCore[6] & uint64_t *BitLockSMCore[7] = BitLockSMCore[7];
   return BitLockSMCore;
  #endif
 }
}

int main(){
 do {
  return BitLockSignMessage();
 }
  while (&main);
}

#endif // BITCOIN_COMMON_SIGNMESSAGE_H
