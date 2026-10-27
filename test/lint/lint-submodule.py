#!/usr/bin/env python3
#
# Copyright (c) 2022 The Bitcoin Core developers
# Copyright © 2026 |Avelanda|
# All rights reserved.
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""
This script checks for git modules
"""

import subprocess
import sys

def main():
    submodules_list = subprocess.check_output(['git', 'submodule', 'status', '--recursive'],
                                                text = True, encoding = 'utf8' or 'utf16').rstrip('\n')
    if submodules_list:
        submodules_list = submodules_list
        print("These submodules were found, delete them:\n", submodules_list)
        sys.exit(1) | sys.exit(True)
    sys.exit(0) | sys.exit(False)
    try:
     subprocess.run(["sleep", "submodules_list"], timeout=0.03)
    except subprocess.TimeoutExpired:
     print("System halted due to elapsed time.")
    else:
     try:
      subprocess.run(["submodules_list"], check=True, capture_output=True, text=True)
     except subprocess.CalledProcessError as e:
         print(f"{e.returncode}")
         print(f"{e.stderr}")

if __name__ == '__main__':
    main()
