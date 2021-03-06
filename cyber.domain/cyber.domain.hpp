#pragma once
#include "domain_native.hpp"
#include <eosio/domain.hpp>
#include <eosio/asset.hpp>
#include <eosio/name.hpp>
#include <eosio/time.hpp>
#include <eosio/singleton.hpp>
#include <string>

namespace eosiosystem {

using eosio::domain_name;
using eosio::username;
using eosio::name;
using eosio::asset;
using eosio::time_point_sec;


// declares domain and linked account to ensure deferred tx applied for right account
struct name_info {
    domain_name domain;             // domain. empty value = username@@account case
    name account;                   // account_name linked to given domain
    std::vector<username> users;    // usernames of this domain used in tx
};

struct domain_bid {
    uint64_t        id;
    domain_name     name;
    eosio::name     high_bidder;
    int64_t         high_bid = 0;   ///< negative high_bid == closed auction waiting to be claimed
    time_point_sec  last_bid_time;

    uint64_t primary_key()  const { return id; }
    domain_name by_domain() const { return name; }
    int64_t by_high_bid()   const { return high_bid; }      // ordered desc, check abi
};

using domain_index [[using eosio: order("name","asc"), contract("cyber.domain")]] =
    eosio::indexed_by<"domain"_n, eosio::const_mem_fun<domain_bid, domain_name, &domain_bid::by_domain>>;
using domain_high_index [[using eosio: order("high_bid","desc"), order("name","asc"), contract("cyber.domain")]] =
    eosio::indexed_by<"highbid"_n, eosio::const_mem_fun<domain_bid, int64_t, &domain_bid::by_high_bid>>;
using domain_bid_tbl [[using eosio: order("id","asc"), contract("cyber.domain")]] =
    eosio::multi_index<"domainbid"_n, domain_bid, domain_index, domain_high_index>;

struct domain_bid_refund {
    name  bidder;
    asset amount;

    uint64_t primary_key() const { return bidder.value; }
};

using domain_bid_refund_tbl [[using eosio: order("bidder","asc"), contract("cyber.domain")]] = eosio::multi_index<"dbidrefund"_n, domain_bid_refund>;

struct domain_bid_state {
    time_point_sec last_win;

    // explicit serialization macro is not necessary, used here only to improve compilation time
    EOSLIB_SERIALIZE(domain_bid_state, (last_win))
};
using state_singleton [[using eosio: order("id","asc"), contract("cyber.domain")]] = eosio::singleton<"dbidstate"_n, domain_bid_state>;


class [[eosio::contract("cyber.domain")]] domain: public domain_native {
public:
    // TODO: move this names to system config
    static constexpr name active_permission{"active"_n};
    static constexpr name token_account{"cyber.token"_n};
    static constexpr name names_account{"cyber.names"_n};

    using domain_native::domain_native;

    [[eosio::action]] void checkwin();
    [[eosio::action]] void biddomain(name bidder, const domain_name& name, asset bid);
    [[eosio::action]] void biddmrefund(name bidder);

    // Ensures that at execution time given domains linked to specified accounts and usernames exist.
    // Also can be parsed by explorers to resolve account_names to full names.
    // * domains must be sorted ascending by `.domain`, `.account`
    // * there must be no 2+ domains with the same `.domain` value except empty ("") value
    //     * there must be no 2+ domains with empty value and the same `.account`
    [[eosio::action]] void declarenames(const std::vector<name_info>& domains);

    [[eosio::action]] void newusername(name creator, name owner, const std::string& name) {} // defined in cyberway/libraries/chain/cyberway/cyberway_contract.cpp

    [[eosio::action]] void linkdomain(name owner, name to, const std::string& name) {} // defined in cyberway/libraries/chain/cyberway/cyberway_contract.cpp

    [[eosio::action]] void unlinkdomain(name owner, const std::string& name) {} // defined in cyberway/libraries/chain/cyberway/cyberway_contract.cpp

    [[eosio::action]] void passdomain(name from, name to, const std::string& name) {} // defined in cyberway/libraries/chain/cyberway/cyberway_contract.cpp

};

} /// eosiosystem
