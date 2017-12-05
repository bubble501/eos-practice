## Navigate to ~/eos/build/programs/eosd and delete the folder “data-dir”

## Open a terminal

## Navigate to ~/eos/build/programs/eosd
'''
cd ~/eos/build/programs/eosd/
'''

## Run the following command:
'''
./eosd
'''

## It should exit with an error

## Navigate to ~/eos/build/programs/eosd/data-dir

## Replace the “config.ini” file with the one in the this repo

## Navigate to ~/eos/build/programs/eosd
'''
cd ~/eos/build/programs/eosd/
'''

## Run the following command:
'''
./eosd
'''

## eosd should now be running and producing blocks

## Open a new terminal and navigate to ~/eos/build/programs/eosc
'''
cd ~/eos/build/programs/eosc/
'''

## Create a wallet
'''
./eosc wallet create
'''

## You should see something like this
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5KKxznFyM1m343Z18xLSVDquTUVTajjCRU8cBJF2rokQdKKB"

## Import the wallet of the “inita” account
'''
./eosc wallet import 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
'''
       
## Create the owner keys
'''
./eosc create key # owner_key
'''

## owner_key
Private key: 5JRx7jWUQ9UVkdeWXrKoSp1cUVGmTmeNSw8ztXE8tkNquGHE
Public key: EOS5TE2w1U6LoA1gWATeRzeSS2bSDzuDMBTeBWFxfKnP8AyMzF

## Create the active keys
'''
./eosc create key # active_key
'''

## active_key
'''
Private key: 5KZXXRrBu1D551PLcPkX6mHwPg3LiPQDkSXhDGbUNkkeR2v3
Public key: EOS7EhX1U2ygEyUqdDi1MsioxZ9FrWjLHpcM7ZsMpy4Qr4rAY9
'''

## Create the hello account
'''
./eosc create account inita hello owner_public_key active_public_key
'''

## Import the active private key of the hello account
'''
./eosc wallet import active_private_key
'''

## Open a new terminal and navigate to ~/eos/build/contracts
'''
cd ~/eos/build/contracts/
'''

## Create a new smart contract
'''
eoscpp -n hello
'''

## Navigate to the hello contract
'''
cd hello
'''

## Compile the contract to a .wast file
'''
eoscpp -o hello.wast hello.cpp
'''

## Open the terminal where ./eosc is available

## Set the hello smart contract onto the locally running eos blockchain
'''
./eosc set contract hello ../../contracts/hello/hello.wast ../../contracts/hello/hello.abi
'''

## Try to call the "greatings" function by sending a message with the "greatings" action
'''
./eosc push message hello greatings '{}' --scope hello,inita --permission hello@active
'''

## See error_report.txt for error output 