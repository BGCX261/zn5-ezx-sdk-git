#!/bin/bash

. ../cross.sh

SDK_NAME=zn5_ezx_sdk
SDK_VERSION=1.2.0

export MOTO_PHONE_MODEL=zn5
export MOTO_PHONE_SDK=${SDK_NAME}-${SDK_VERSION}
export QTDIR=${PATH_WORK_ROOT}/zn5_e8_ezx_sdk
export TMAKEPATH=${QTDIR}/tmakelib/pwd/arm-linux-g++/
export PATH=${QTDIR}/bin:${PATH}

