// Copyright (c) 2011-2013 The Bitcoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p259201 = uint256("0x000008f98da9a790d44ff144e24262fe56d9f7ce7000b7c30c84c45da5c895a9");
    uint256 p623933 = uint256("0x000002ad7099c49f639bcf82c5d8c390897624326579100511dcfa88ab6684f4");
    BOOST_CHECK(Checkpoints::CheckBlock(0, p259201));
    BOOST_CHECK(Checkpoints::CheckBlock(2, p623933));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(0, p623933));
    BOOST_CHECK(!Checkpoints::CheckBlock(2, p259201));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p623933));
    BOOST_CHECK(Checkpoints::CheckBlock(2+1, p259201));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 2);
}

BOOST_AUTO_TEST_SUITE_END()
