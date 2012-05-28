#!/bin/bash

MOTO_PHONE_MODEL=zn5
HOST_OS=`uname -o`
export PATH_WORK_ROOT=/home/fuzhuo/mypro/moto_ezx/zn5_e8_ezx_sdk
export TOOLCHAIN_VERSION=zn5-gcc
export TOOLCHAIN_PREFIX=arm-linux-gnueabi

# 
# tool  
#  
#export PATH_WORK_TOOL=${PATH_WORK_ROOT}/arm-eabi
export PATH_WORK_TOOL=${PATH_WORK_ROOT}/toolchain/zn5-gcc
export PATH_TOOLCHAIN_ROOT=${PATH_WORK_TOOL}
export PATH_TOOLCHAIN_BIN=${PATH_TOOLCHAIN_ROOT}/bin

#  
# Export ALL PATH  
#  
export PATH=${PATH_TOOLCHAIN_BIN}:/bin:/sbin:/usr/bin:/usr/sbin
#export PATH=/arm-eabi/bin:/bin:/sbin:/usr/bin:/usr/sbin
export CROSS_COMPILE=${TOOLCHAIN_PREFIX}-

echo ------------------------------------------
echo PHONE:	$MOTO_PHONE_MODEL
echo HOST:	$HOST_OS
echo tool_path:	$PATH_WORK_ROOT
echo Version:	$TOOLCHAIN_VERSION
echo ------------------------------------------

SDK_NAME=zn5_ezx_sdk
SDK_VERSION=1.2.0

export MOTO_PHONE_MODEL=zn5
export MOTO_PHONE_SDK=${SDK_NAME}-${SDK_VERSION}
export QTDIR=${PATH_WORK_ROOT}/zn5_ezx_sdk
export TMAKEPATH=${QTDIR}/tmakelib/pwd/arm-linux-g++/
export PATH=${QTDIR}/bin:${PATH}

