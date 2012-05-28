#!/bin/bash

LIBNAME=$1
LIBVER=$2
LIBTYPE=$3
LIBMAKE=$4

if [[ "" = ${LIBTYPE} ]]; then
	LIBTYPE=dynamic
fi

TARGETDIR=${QTDIR}/target/lib

LIBEXTS=a
LIBEXTD=so
LIBVNAME=${LIBNAME}-${LIBVER}
LIBFNAME=lib${LIBVNAME}
# dynamic lib will be linked if .so and .a both exist, so delete before build
if [ ${LIBTYPE} = "static" ]; then
	rm -f ${TARGETDIR}/${LIBFNAME}.${LIBEXTD}
	LIBEXT=${LIBEXTS}
elif [ ${LIBTYPE} = "dynamic" ]; then
	rm -f ${TARGETDIR}/${LIBFNAME}.${LIBEXTS}
	LIBEXT=${LIBEXTD}
fi
LIBFILE=${LIBFNAME}.${LIBEXT}
LIBCMD=lib${LIBEXT}

if [[ ( ${LIBINAME} != "" ) && ( ${LIBINAME} != "NULL" ) ]]; then
	for n in ${LIBINAME}; do
		LIBINCL="${LIBINCL} -I${n}"
	done
	export LIBINCL
fi

export LIBNAME
export LIBVNAME
export LIBCMD

echo -------------------------------------------------------------------------------
mkdir -p lib ${TARGETDIR}
if [[ ( ${LIBMAKE} != "" ) && ( ${LIBMAKE} != "NULL" ) ]]; then
	${LIBMAKE}
else
	make clean -s
	make ${LIBCMD}
fi
mv -f lib/${LIBFILE} ${TARGETDIR}
make cleantmp -s
rm -rf lib Makefile
echo -------------------------------------------------------------------------------
