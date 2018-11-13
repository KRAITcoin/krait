// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The Krait developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

/*   height=259203 (check)
 *   CBlock(hash=c8185ff87fbed4ea802e134b2b9ac7af370d5de390f988dd3cf19969bdb80561, ver=3, hashPrevBlock=6f84462020442facb64b112c25e5a4789ab0c047140615fcde790f29ef1bce8b, hashMerkleRoot=ca6bbbde74b07cb003ed64b95653e9e23aea4426b1a471c66d081f909ca00f2f, 
 *   nTime=1541831423, nBits=1c36aa45, nNonce=0, vtx=2)
 *   CTransaction(hash=af3a336f8a, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *   CTxIn(COutPoint(0000000000000000000000000000000000000000000000000000000000000000, 4294967295), coinbase 0382f4030101)
 *   CTxOut(nValue=0.00000000, scriptPubKey=)
 *   CTransaction(hash=1da7b2e355, ver=1, vin.size=1, vout.size=4, nLockTime=0)
 *   CTxIn(COutPoint(2c42b1b74cf337cef80c110fbb44e63942837ca0b1d4161351409072255bd3e5, 1), scriptSig=30450221008368717f641667)
 *   CTxOut(nValue=0.00000000, scriptPubKey=)
 *   CTxOut(nValue=2501.49000000, scriptPubKey=03feafc9cdc17016fe09cc1130df58)
 *   CTxOut(nValue=2498.95998520, scriptPubKey=03feafc9cdc17016fe09cc1130df58)
 *   CTxOut(nValue=2.55000000, scriptPubKey=OP_DUP OP_HASH160 1aedcd343950)
 *   vMerkleTree:  af3a336f8a7f1694a878292bb5942b1f1c62735586d15b7abdd5f304972f1a2d 1da7b2e3556bdf6b9ce38d17351aba5a127b65898763e594ce1d44fa4e57afb6 ca6bbbde74b07cb003ed64b95653e9e23aea4426b1a471c66d081f909ca00f2f

 height=260239
 CBlock(hash=42e773c4aaef5e93ed97693f58752cfda9a114a3d22ed7ba450c9907ee08442b, ver=3, hashPrevBlock=52f751472cfebefa20c44a9b7bb259b9833a87570095dec98d59868a53498cd1, hashMerkleRoot=20b8dcaef3b45fee5eefee1c0d94628c1ed9147f09b5e04438f2eb3fc33aa538,
 nTime=1541884991, nBits=1b0b0f41, nNonce=0, vtx=2) tx=296328 
  CTransaction(hash=cf6483cee6, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    CTxIn(COutPoint(0000000000000000000000000000000000000000000000000000000000000000, 4294967295), coinbase 038ff8030101)
    CTxOut(nValue=0.00000000, scriptPubKey=)

  CTransaction(hash=10d0403c89, ver=1, vin.size=1, vout.size=3, nLockTime=0)
    CTxIn(COutPoint(c76180cab99b2ce4996719ac5d33e61734fd99a8ac6bbd09422ee3a287f29d60, 1), scriptSig=3045022100ba8bfb601c0ab4)
    CTxOut(nValue=0.00000000, scriptPubKey=)
    CTxOut(nValue=2213.04998960, scriptPubKey=028d89f9489f6f6e3c1f5e26453853)
    CTxOut(nValue=2.55000000, scriptPubKey=OP_DUP OP_HASH160 165e84cec4fc)

  vMerkleTree:  cf6483cee66faa048f6b14ed88b78f8041b28371812f12fe1275c7878a5837cf 10d0403c89b14cdb7fa35f4855c826bbf8a3e5550066fe9867c52d635f21782f 20b8dcaef3b45fee5eefee1c0d94628c1ed9147f09b5e04438f2eb3fc33aa538
 */
 
 
 


static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x000008f98da9a790d44ff144e24262fe56d9f7ce7000b7c30c84c45da5c895a9"))
	(2, uint256("0x000002ad7099c49f639bcf82c5d8c390897624326579100511dcfa88ab6684f4"))
    (246325, uint256("0x000000001102e9a145f2e2cae79c28eb8b202bcefc74a2dd54e211efd1984581"))	// last block old blockchain
	(246326, uint256("0x000000000dbfa11fcedaefcf34ef84b029903789b20bfb51b95e9d56f84d24d8")) //rollback chain fix graviex scam
	(248318, uint256("000000056d91d8cf163ccfefdef912649d97c66aa37422adedad8b7d0bfd76ce"))  //stable block
	(260239, uint256("42e773c4aaef5e93ed97693f58752cfda9a114a3d22ed7ba450c9907ee08442b")); .//fix split chain after pos
	
	
	
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1541884991, // * UNIX timestamp of last checkpoint block
    296328,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2880        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x02;
        pchMessageStart[1] = 0x2a;
        pchMessageStart[2] = 0x0c;
        pchMessageStart[3] = 0xa1;
        vAlertPubKey = ParseHex("0484d90e17b407221bc32d44832716418f090c323c594749d66adf3ff5c630bad489712738ada058d25a676f3dfa964258db28d3dbb58097f03cc8f2b4d22eb8e5");
        nDefaultPort = 60021;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Krait starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Krait: 1 minute
        nTargetSpacing = 1 * 60;  // Krait: 1 minute
        nMaturity = 6;
		nMaxMoneyOut = 10000000000 * COIN;
        /** Height or Time Based Activations **/
        nLastPOWBlock = 259200;
        nModifierUpdateBlock = 1;
		
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nZerocoinStartHeight = 259300; 
        nZerocoinStartTime = 1541884992;  // 11/10/2018 @ 9:23pm (UTC)
		
		const char* pszTimestamp = "KRAIT 18-02-2018";
		
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
				
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0484d90e17b407221bc32d44832716418f090c323c594749d66adf3ff5c630bad489712738ada058d25a676f3dfa964258db28d3dbb58097f03cc8f2b4d22eb8e5") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1520530811;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 20853759;
        hashGenesisBlock = genesis.GetHash();
		
        assert(hashGenesisBlock == uint256("0x000008f98da9a790d44ff144e24262fe56d9f7ce7000b7c30c84c45da5c895a9"));
        assert(genesis.hashMerkleRoot == uint256("0xd937e75cb33178449539789d86288a0cf8280a095113c0ef19a3a2f1cdff1c7b"));
	    vFixedSeeds.clear();
        vSeeds.clear();
		

		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
        strSporkKey = "0484d90e17b407221bc32d44832716418f090c323c594749d66adf3ff5c630bad489712738ada058d25a676f3dfa964258db28d3dbb58097f03cc8f2b4d22eb8e5";
        
        strObfuscationPoolDummyAddress = "Sg3aLcSeLqbpEsVgoXtDFrpDYDfAsf1qxv";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 2;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Krait: 1 day
        nTargetSpacing = 1 * 60;  // Krait: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));
        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("194.87.101.240", "194.87.101.240"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet krait addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet krait script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet krait BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet krait BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet krait BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short 
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Krait: 1 day
        nTargetSpacing = 1 * 60;        // Krait: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
	case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
