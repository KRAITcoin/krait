sudo apt-get install build-essential libtool autotools-dev automake autoconf pkg-config libssl-dev libevent-dev bsdmainutils libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev libboost-all-dev git -y
sudo apt-get install software-properties-common -y
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update && apt-get install libdb4.8-dev libdb4.8++-dev -y
git clone https://github.com/KRAITcoin/krait 
chmod -R a+rwx Krait
cd Krait
bash autogen.sh
./configure --disable-test --with-incompatible-bdb
make
make install
