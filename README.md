<img width="400" src="./docs/logo.jpg" />  

*****  
[![buildkite](https://badge.buildkite.com/f0940b2380542f6c80c1c01aa773d61c1d3470007fa5b9e6c3.svg?branch=master)](https://buildkite.com/cyberway.contracts)
[![GitHub](https://img.shields.io/github/license/cyberway/cyberway.contracts.svg)](https://github.com/cyberway/cyberway.contracts/blob/master/LICENSE)  


# CyberWay Contracts

## Version : 2.0.1

The design of the CyberWay blockchain calls for a number of smart contracts that are run at a privileged permission level in order to support functions such as validator registration and voting, token staking for CPU and network bandwidth, RAM purchasing, multi-sig, etc.  

This repository contains contracts that are useful when deploying, managing, and/or using CyberWay blockchain. They are provided for reference purposes:

  * [cyber.bios](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.bios)
  * [cyber.domain](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.domain)
  * [cyber.govern](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.govern)
  * [cyber.msig](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.msig)
  * [cyber.stake](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.stake)
  * [cyber.token](https://github.com/cyberway/cyberway.contracts/tree/master/cyber.token)

Dependencies:
* [cyberway v2.0.x](https://github.com/cyberway/cyberway/releases)
* [cyberway.cdt v2.0.x](https://github.com/cyberway/cyberway.cdt/tags)

To build the contracts and the unit tests:
* First, ensure that your __cyberway__ is compiled to the core symbol for the CyberWay blockchain that intend to deploy to.
* Second, make sure that you have ```sudo make install```ed __cyberway__.
* Then just run the ```build.sh``` in the top directory to build all the contracts and the unit tests for these contracts.

After build:
* The unit tests executable is placed in the _build/tests_ and is named __unit_test__.
* The contracts are built into a _bin/\<contract name\>_ folder in their respective directories.
* Finally, simply use __cleos__ to _set contract_ by pointing to the previously mentioned directory.

## System Contracts Description
* [cyber.bios](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.bios_contract)
* [cyber.domain](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.domain_contract)
* [cyber.govern](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.govern_contract)
* [cyber.msig](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.msig_contract)
* [cyber.stake](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.stake_contract)
* [cyber.token](https://cyberway.gitbook.io/en/devportal/system_contracts/cyber.token_contract)

