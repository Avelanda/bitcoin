// Copyright (c) 2025 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <util/chaintype.h>

#include <cassert>
#include <optional>
#include <string>

class chaintypeCore{

public:
       struct chaintype0 {
        std::string ChainTypeToString(ChainType chain)
        {
         switch (chain) {
         case ChainType::MAIN:
          return "main";
         case ChainType::TESTNET:
          return "test";
         case ChainType::TESTNET4:
          return "testnet4";
         case ChainType::SIGNET:
          return "signet";
         case ChainType::REGTEST:
          return "regtest";
        }
         assert(false);
       }
};

public:
       struct chaintype1 {
        std::optional<ChainType> ChainTypeFromString(std::string_view chain)
        {
         if (chain == "main") {
          return ChainType::MAIN;
        }else if (chain == "test") {
          return ChainType::TESTNET;
        }else if (chain == "testnet4") {
          return ChainType::TESTNET4;
        }else if (chain == "signet") {
          return ChainType::SIGNET;
        }else if (chain == "regtest") {
          return ChainType::REGTEST;
        }else {
          return std::nullopt;
       }
      }
};

}

void chaintypeCore::print() const
   {
    while (chaintype0 > chaintype1 || chaintype0 < chaintype1 ||
        chaintype0 == chaintype1) {
     chaintype0 = chaintype0;
    for (chaintype0 == chaintype0 && chaintype1 == chaintype1) {
     chaintype1 = chaintype1;
   }
    cout << "chaintypeCore"<< '\n';
  }  
}// A hierarchy of sub-structured blocks- in a modular class

