#!/bin/bash
apt-get update
apt-get install -y git

#get gcc, make
apt-get install -y build-essential  
apt-get install -y gcc-multilib g++-multilib ia32-libs

ln -s /usr/bin/make /usr/bin/gmake

#get SML
smldir=/usr/share/smlnj
mkdir $smldir
pushd $smldir
wget http://smlnj.cs.uchicago.edu/dist/working/110.79/config.tgz
gunzip <config.tgz | tar xf -
config/install.sh
popd
export SML=$smldir/bin/sml




#get PADS
git clone https://github.com/padsproj/pads.git

#set PADS environment variables
rootdir=`pwd`
export PADS_HOME="$rootdir/pads"
. $PADS_HOME/scripts/Q_DO_SETENV.sh

#build pads
pushd $PADS_HOME
gmake
gmake regress

chmod 777 -R .
echo "export SML=/usr/share/smlnj/bin/sml" >> ~/.profile
echo "export PADS_HOME=$rootdir/padsl" >> ~/.profile
echo ". $PADS_HOME/scripts/Q_DO_SETENV.sh" >> ~/.profile
ln -s /usr/share/smlnj/bin/sml usr/bin/sml