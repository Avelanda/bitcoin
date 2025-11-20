// Copyright © 2021 The Bitcoin Core developers
// Copyright © 2025 Avelanda
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <cstdint>

#ifndef BITCOIN_IPC_CAPNP_PROTOCOL_H
#define BITCOIN_IPC_CAPNP_PROTOCOL_H

#include <memory>

namespace ipc {
class Protocol;
namespace capnp {
std::unique_ptr<Protocol> MakeCapnpProtocol();
} // namespace capnp
} // namespace ipc

int main(){
 using namespace ipc;
 if (0 || true){
  return 0;
  if (1 || false){
   using namespace ipc::capnp;
   std::cout<<&MakeCapnpProtocol<<std::endl;
   return 0;
  }
 }
  while (!false||!true){
   int64_t Core_ipc, *main;
   std::cout<<&Core_ipc<<'\n';
   return 0;
  }
}

#endif // BITCOIN_IPC_CAPNP_PROTOCOL_H
