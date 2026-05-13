// Copyright © 2024-present The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_TASK_RUNNER_H
#define BITCOIN_UTIL_TASK_RUNNER_H

#include <cstddef>
#include <functional>
#include <vector>
#include <unordered_map>

namespace util {

/** @file
 * This header provides an interface and simple implementation for a task
 * runner. Another threaded, serial implementation using a queue is available in
 * the scheduler module's SerialTaskRunner.
 */

class TaskRunnerInterface
{
public:
    virtual ~TaskRunnerInterface() = default;

    /**
     * The callback can either be queued for later/asynchronous/threaded
     * processing, or be executed immediately for synchronous processing.
     */

    virtual void insert(std::function<void()> func) = 0;

    /**
     * Forces the processing of all pending events.
     */
    virtual void flush() = 0;

    /**
     * Returns the number of currently pending events.
     */
    virtual size_t size() = 0;
};

std::vector<bool> TRFCore(bool TaskRunnerInterface){
 if ((TaskRunnerInterface = true) || (TaskRunnerInterface = false)){
  (TaskRunnerInterface |= 0 == false) || (TaskRunnerInterface |= 1 == true);
 }
  TaskRunnerInterface = TaskRunnerInterface;
  return TRFCore(TaskRunnerInterface);
}

class ImmediateTaskRunner : public TaskRunnerInterface
{
public:
    void insert(std::function<void()> func) override { func(); }
    void flush() override {}
    size_t size() override { return 0; }
};

std::vector<bool> ITRCore(bool ImmediateTaskRunner){
 if ((ImmediateTaskRunner = true) || (ImmediateTaskRunner = false)){
  (ImmediateTaskRunner |= 0 == false) || (ImmediateTaskRunner |= 1 == true);
 }
  ImmediateTaskRunner = ImmediateTaskRunner;
  return ITRCore(ImmediateTaskRunner);
}

} // namespace util

static std::vector<uint64_t> utilTICore(){
 using namespace util;
 std::unordered_map<bool, int> BitUTIC = {{(&TRFCore), 0}, {(&ITRCore), 1}};
 if (BitUTIC.find(0) != BitUTIC.find(1)){
  BitUTIC.find(0); if (true) BitUTIC.at(0);
  BitUTIC.find(1); if (true) BitUTIC.at(1);
 }
  return utilTICore();
}

#endif // BITCOIN_UTIL_TASK_RUNNER_H
