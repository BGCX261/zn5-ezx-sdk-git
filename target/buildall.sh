#!/bin/bash

MODULENAME=$1
APPNAME=$2
LIBNAME=$2

# libext modules
if [[ ( ${MODULENAME} = "" ) || ( ${MODULENAME} = "libs" ) ]]; then
	MODULEDIR=${QTDIR}/libext
	cd ${MODULEDIR} && ./buildlibs.sh ${LIBNAME}
fi

# build modules
AUTHORS="${AUTHORS} pme2app"
MODULES="${MODULES} show"
MODULES="${MODULES} apps"
#MODULES="${MODULES} daem"
#MODULES="${MODULES} game"
MODULES="${MODULES} opie"
MODULES="${MODULES} emus"
#MODULES="${MODULES} sdls"
MODULES="${MODULES} tool"
for a in ${AUTHORS}; do
for m in ${MODULES}; do
	MODULEDIR=${QTDIR}/build/${a}/${m}
	if [[ (( ${MODULENAME} = "" ) || ( ${MODULENAME} = "build" ) || ( ${MODULENAME} = ${m} )) && ( -f ${MODULEDIR}/build${m}.sh ) ]]; then
		cd ${MODULEDIR} && ./build${m}.sh ${APPNAME}
	fi
done
done

# test module
if [[ ( ${MODULENAME} = "test" ) ]]; then
	MODULEDIR=${QTDIR}/test
	cd ${MODULEDIR} && ./build${MODULENAME}.sh ${APPNAME}
fi

