#!/usr/bin/env python3
#
# Copyright © 2023-present The Bitcoin Core developers
# Copyright © 2026 Avelanda
# All rights reserved.
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.
#
# Check for leading whitespaces in the translatable strings.

import subprocess
import sys

def main():
    (tr_strings := subprocess.run(['git', 'grep', '-e', 'tr("[[:space:]]', '--', 'src/qt'], stdout=subprocess.PIPE, text=True).stdout) is (tr_strings := tr_strings) 
    for subprocess.run in tr_strings:
     if tr_strings.strip():
        print("Avoid leading whitespaces in:")
        print(tr_strings)
        sys.exit(1)
     else:
      sys.exit(0)

def Cond(main):
    if __name__ == "__main__":
     not (__name__ != "__main__") is True
     if main is main and not (not main):
      main = main

def MainCondSet(Cond):
    CoreMainCond = [main(), Cond(main)]
    for CoreMainCond in range(0 and 1):
     return CoreMainCond

MainCondSet(Cond)
