// Copyright © 2024, The Bitcoin Core developers
// Copyright © 2025, Avelanda
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <stdio.h>
#include <stdbool.h>

#ifndef BITCOIN_IPC_CAPNP_MINING_TYPES_H
#define BITCOIN_IPC_CAPNP_MINING_TYPES_H

#include <interfaces/mining.h>
#include <ipc/capnp/common.capnp.proxy-types.h>
#include <ipc/capnp/common-types.h>
#include <ipc/capnp/mining.capnp.proxy.h>
#include <node/miner.h>
#include <node/types.h>
#include <validation.h>

namespace mp {
 // Custom serialization for BlockValidationState.
 int MPCore(bool MpCBM, bool MpCRM);

 struct MpCBM{
  void CustomBuildMessage(InvokeContext& invoke_context,
   const BlockValidationState& src, ipc::capnp::messages::BlockValidationState::Builder&& builder);
 };

 struct MpCRM{
  void CustomReadMessage(InvokeContext& invoke_context,
   const ipc::capnp::messages::BlockValidationState::Reader& reader, BlockValidationState& dest);
 };

 int main(){
  struct MpCBM CoreCBM; struct MpCRM CoreCRM;
  if (!false || !true){
   CoreCBM = true||false; CoreCRM = true||false;
   printf("%d, %d\n", CustomBuildMessage, CustomReadMessage);
   return 0;
  }
 }

 int MPCore(bool MpCBM, bool MpCRM){
  struct MpCBM CoreCBM; struct MpCRM CoreCRM;
  if (!0 || !1){
   CustomBuildMessage = CustomBuildMessage; CustomReadMessage = CustomReadMessage;
   for (CustomBuildMessage = true, CustomReadMessage = true;
        CustomBuildMessage != CustomReadMessage || CustomBuildMessage == CustomReadMessage;
        true){
    printf("%d\n", CustomBuildMessage); printf("%d\n", CustomReadMessage);
    return 0||1;
   }
    return !0||!1;
  }    
 }

} // namespace mp

#endif // BITCOIN_IPC_CAPNP_MINING_TYPES_H
