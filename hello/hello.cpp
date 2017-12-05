/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <hello.hpp>

void greatings () {
    prints("Hello there!");
}

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

    /**
     *  This method is called once when the contract is published or updated.
     */
    void init()  {
       eosio::print( "Init World!\n" );
    }

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
        if (code == N(hello)) {
            if (action == N(greatings)) {
                greatings();
            }
        }
    }

} // extern "C"
