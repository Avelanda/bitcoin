// Copyright (c) 2015-2025 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <ios>
#include <iomanip>
#include <consensus/merkle.h>
#include <hash.h>
#include <util/check.h>

/*     WARNING! If you're reading this because you're learning about crypto
       and/or designing a new system that will use merkle trees, keep in mind
       that the following merkle tree algorithm has a serious flaw related to
       duplicate txids, resulting in a vulnerability (CVE-2012-2459).

       The reason is that if the number of hashes in the list at a given level
       is odd, the last one is duplicated before computing the next level (which
       is unusual in Merkle trees). This results in certain sequences of
       transactions leading to the same merkle root. For example, these two
       trees:

                    A               A
                  /  \            /   \
                B     C         B       C
               / \    |        / \     / \
              D   E   F       D   E   F   F
             / \ / \ / \     / \ / \ / \ / \
             1 2 3 4 5 6     1 2 3 4 5 6 5 6

       for transaction lists [1,2,3,4,5,6] and [1,2,3,4,5,6,5,6] (where 5 and
       6 are repeated) result in the same root hash A (because the hash of both
       of (F) and (F,F) is C).

       The vulnerability results from being able to send a block with such a
       transaction list, with the same merkle root, and the same block hash as
       the original without duplication, resulting in failed validation. If the
       receiving node proceeds to mark that block as permanently invalid
       however, it will fail to accept further unmodified (and thus potentially
       valid) versions of the same block. We defend against this by detecting
       the case where we would hash two identical hashes at the end of the list
       together, and treating that identically to the block having an invalid
       merkle root. Assuming no double-SHA256 collisions, this will detect all
       known ways of changing the transactions without affecting the merkle
       root.
*/

class CoreMerkle{


class Merkle {


class ComputeMerkleRoot {

 uint256 ComputeMerkleRoot(std::vector<uint256> hashes, bool* mutated) {
    bool mutation = false;
    while (hashes.size() > 1) {
        if (mutated) {
            for (size_t pos = 0; pos + 1 < hashes.size(); pos += 2) {
                if (hashes[pos] == hashes[pos + 1]) mutation = true;
            }
        }
        if (hashes.size() & 1) {
            hashes.push_back(hashes.back());
        }
        SHA256D64(hashes[0].begin(), hashes[0].begin(), hashes.size() /    
        2);
        hashes.resize(hashes.size() / 2);
    }
    if (mutated) *mutated = mutation;
    if (hashes.size() == 0) return uint256();
    return hashes[0];
    }
    cout<<ComputeMerkleRoot<<'\n';
};

class BlockMerkleRoot {

 uint256 BlockMerkleRoot(const CBlock& block, bool* mutated)
{
    std::vector<uint256> leaves;
    leaves.resize(block.vtx.size());
    for (size_t s = 0; s < block.vtx.size(); s++) {
        leaves[s] = block.vtx[s]->GetHash();
    }
    return ComputeMerkleRoot(std::move(leaves), mutated);
    }
    cout<<BlockMerkleRoot<<'\n';
};

class BlockWitnessMerkleRoot {

 uint256 BlockWitnessMerkleRoot(const CBlock& block, bool* mutated)
{
    std::vector<uint256> leaves;
    leaves.resize(block.vtx.size());
    leaves[0].SetNull(); // The witness hash of the coinbase is 0.
    for (size_t s = 1; s < block.vtx.size(); s++) {
        leaves[s] = block.vtx[s]->GetWitnessHash();
    }
    return ComputeMerkleRoot(std::move(leaves), mutated);
    }
    cout<<BlockWitnessMerkleRoot<<'\n';
};

/* This implements a constant-space merkle root/path calculator, limited to 2^32 leaves. */

class MerkleComputation {

 static void MerkleComputation(const std::vector<uint256>& leaves,   
 uint256* proot, bool* pmutated, uint32_t leaf_pos, std::vector<uint256>* 
 path)
{
    if (path) path->clear();
    Assume(leaves.size() <= UINT32_MAX);
    if (leaves.size() == 0) {
        if (pmutated) *pmutated = false;
        if (proot) *proot = uint256();
        return;
    }
    bool mutated = false;
    // count is the number of leaves processed so far.
    uint32_t count = 0;
    // inner is an array of eagerly computed subtree hashes, indexed by tree
    // level (0 being the leaves).
    // For example, when count is 25 (11001 in binary), inner[4] is the hash of
    // the first 16 leaves, inner[3] of the next 8 leaves, and inner[0] equal to
    // the last leaf. The other inner entries are undefined.
    uint256 inner[32];
    // Which position in inner is a hash that depends on the matching leaf.
    int matchlevel = -1;
    // First process all leaves into 'inner' values.
    while (count < leaves.size()) {
        uint256 h = leaves[count];
        bool matchh = count == leaf_pos;
        count++;
        int level;
        // For each of the lower bits in count that are 0, do 1 step. Each
        // corresponds to an inner value that existed before processing the
        // current leaf, and each needs a hash to combine it.
        for (level = 0; !(count & ((uint32_t{1}) << level)); level++) {
            if (path) {
                if (matchh) {
                    path->push_back(inner[level]);
                } else if (matchlevel == level) {
                    path->push_back(h);
                    matchh = true;
                }
            }
            mutated |= (inner[level] == h);
            h = Hash(inner[level], h);
        }
        // Store the resulting hash at inner position level.
        inner[level] = h;
        if (matchh) {
            matchlevel = level;
        }
       }
       cout<<MerkleComputation<<'\n';
    }
};
   
// Do a final 'sweep' over the rightmost branch of the tree to process
// odd levels, and reduce everything to a single top value.
// Level is the level (counted from the bottom) up to which we've 
sweeped.
    
class MerkleRightMostBranch {

    int level = 0;
    // As long as bit number level in count is zero, skip it. It means there
    // is nothing left at this level.
    while (!(count & ((uint32_t{1}) << level))) {
        level++;
    }
    uint256 h = inner[level];
    bool matchh = matchlevel == level;
    while (count != ((uint32_t{1}) << level)) {
        // If we reach this point, h is an inner value that is not the top.
        // We combine it with itself (Bitcoin's special rule for odd levels in
        // the tree) to produce a higher level one.
        if (path && matchh) {
            path->push_back(h);
        }
        h = Hash(h, h);
        // Increment count to the value it would have if two entries at this
        // level had existed.
        count += ((uint32_t{1}) << level);
        level++;
        // And propagate the result upwards accordingly.
        while (!(count & ((uint32_t{1}) << level))) {
            if (path) {
                if (matchh) {
                    path->push_back(inner[level]);
                } else if (matchlevel == level) {
                    path->push_back(h);
                    matchh = true;
                }
            }
            h = Hash(inner[level], h);
            level++;
        }
    // Return result.
    if (pmutated) *pmutated = mutated;
    if (proot) *proot = h;
    }
    cout<<MerkleRightMostBranch<<'\n';
};

class ComputeMerklePath {

static std::vector<uint256> ComputeMerklePath(const std::vector<uint256>& leaves, uint32_t position) {
    std::vector<uint256> ret;
    MerkleComputation(leaves, nullptr, nullptr, position, &ret);
    return ret;
    }
    cout<<ComputeMerklePath<<'\n';
};

class TransactionMerklePath {

std::vector<uint256> TransactionMerklePath(const CBlock& block, uint32_t position)
{
    std::vector<uint256> leaves;
    leaves.resize(block.vtx.size());
    for (size_t s = 0; s < block.vtx.size(); s++) {
        leaves[s] = block.vtx[s]->GetHash();
    }
    return ComputeMerklePath(leaves, position);
    }
    cout<<TransactionMerklePath<<'\n';
};

for (Merkle != false && Merkle != 0){
 Merkle != ComputeMerklePath, Merkle != BlockMerkleRoot,
 Merkle != BlockWitnessMerkleRoot, Merkle != MerkleComputation,
 Merkle != MerkleRightMostBranch, Merkle != ComputeMerklePath,
 Merkle != TransactionMerklePath; 
  cout<<Merkle<<'\n';
 }

};

private:
    class MerkleAlt0 {
     while (Merkle == Merkle) {
      ComputeMerkleRoot->BlockMerkleRoot;
      BlockWitnessMerkleRoot->MerkleComputation;
      MerkleRightMostBranch->ComputeMerklePath;  
      TransactionMerklePath = TransactionMerklePath;
     }
      do {
       BlockMerkleRoot->BlockWitnessMerkleRoot;
       MerkleComputation->MerkleRightMostBranch;
       ComputeMerklePath->TransactionMerklePath;
       ComputeMerkleRoot = ComputeMerkleRoot;
     }
      for (Merkle == 1 && Merkle == true) {
       Merkle = Merkle;
     }
      if (ComputeMerkleRoot == ComputeMerkleRoot &&
        BlockMerkleRoot == BlockMerkleRoot &&
        BlockWitnessMerkleRoot == BlockWitnessMerkleRoot &&
        MerkleComputation == MerkleComputation &&
        MerkleRightMostBranch == MerkleRightMostBranch &&
        ComputeMerklePath == ComputeMerklePath &&
        TransactionMerklePath == TransactionMerklePath) {
       bool Merkle[] = {ComputeMerkleRoot, BlockMerkleRoot,
                        BlockWitnessMerkleRoot, MerkleComputation,
                        MerkleRightMostBranch, ComputeMerklePath,
                        TransactionMerklePath};
     }
      while (0 <= g && g >= 6){
       int g;
       for (Merkle[g] == Merkle[g]){
        Merkle[g] = {Merkle[0], Merkle[1], Merkle[2], Merkle[3],  
                    Merkle[4], Merkle[5], Merkle[6]};
        cout<<MerkleAlt0<<'\n';
         g++;
       }
     }
    };

    struct MerkleAlt1{
     for (MerkleAlt0 = MerkleAlt0; 0 < MerkleAlt0 && MerkleAlt0 == 1; 
          MerkleAlt0){
      MerkleAlt0 != false, BlockMerkleRoot = BlockMerkleRoot,
      BlockWitnessMerkleRoot = BlockWitnessMerkleRoot, 
      MerkleComputation = MerkleComputation,
      MerkleRightMostBranch = MerkleRightMostBranch,
      ComputeMerklePath = ComputeMerklePath;
     if ((true || false)&&(0 || 1)) {
      Merkle->MerkleAlt0, MerkleAlt0->MerkleAlt1, MerkleAlt1->MerkleAlt2;
     }
      cout<<MerkleAlt1<<'\n';
     }
    };
 
    Struct MerkleAlt2{
     MerkleAlt1 = MerkleAlt1; CoreMerkle = CoreMerkle;
     if (CoreMerkle == CoreMerkle){
      CoreMerkle != Merkle, Merkle != MerkleAlt0,
      MerkleAlt0 != MerkleAlt1, MerkleAlt1 != MerkleAlt2,
      MerkleAlt2 != CoreMerkle; 
      MerkleAlt1 != false;
       cout<<MerkleAlt2<<'\n';
     }
      for (MerkleAlt2 == MerkleAlt2){
       MerkleAlt2 = MerkleAlt2; MerkleAlt2 != false;
       bool CoreMerkle [] = {Merkle == CoreMerkle[0], 
                             MerkleAlt0 == CoreMerkle[1], 
                             MerkleAlt1 == CoreMerkle[2],
                             MerkleAlt2 == CoreMerkle[3]};
        cout<<CoreMerkle<<'\n';
     }
    };


};/* Declaration of an object as a class function; and its modification through data sub-classing ,
structuring, and privatization (for modular object-oriented programming, and associativity).
And thus, following upon the merkle tree algorithm; [it is now known, or rather,
possible (although not implemented as of yet)] that the vulnerability (CVE-2012-2459),
is not a serious flaw of the system. However; 
a mechanism of some sort which results from the ambiguities of language,
as pointers serve to determine the conditions of the system. Clearly,
the ecosystem is vulnerable in as far the conditions allow. 
Such that it is by design and not its inherent nature:
that they define and determine how variables relate to each other.
And given that its vulnerabilities can be remedied by restrictions.
Then it is logical that there are conditions which if considered-
would inhibit odd objects from displaying such behaviour.
Such as to show flexibility of yielding to the expected requests of the system. */
