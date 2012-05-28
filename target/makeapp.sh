#!/bin/bash

APPNAME=$1
DOPROGEN=$2
DOTMAKE=$3
DOCLEAN=$4
TARGETDIR=${QTDIR}/target/bin

echo -------------------------------------------------------------------------------

####################################################################################
#	if to link ${LIBVNAME}
####################################################################################
if [[ ( ${LIBLNAME} != "" ) && ( ${LIBLNAME} != "NULL" ) ]]; then
	# some apps such as dosbox, do not link to ${LIBVNAME}, so don't export LIBLINK
	for n in ${LIBLNAME}; do
		LIBLINK="${LIBLINK} -l${n}"
	done
	export LIBLINK
fi

####################################################################################
#	if to do progen
####################################################################################
if [[ ( ${DOTMAKE} != "" ) && ( ${DOTMAKE} != "yes" ) ]]; then
	# some apps such as ???, use specific Makefile, don't execute tmake and progen, so pro file is useless, remove it after make if exist
	RMPRO=yes
elif [[ ( ${DOPROGEN} != "" ) && ( ${DOPROGEN} != "yes" ) ]]; then
	# some apps such as dosbox, use specific ${APPNAME}.pro, don't execute progen, and don't remove it after make
	RMPRO=no
else
	# apps use progen to generate ${APPNAME}.pro, remove after make
	progen -o ${APPNAME}.pro
	echo OBJECTS_DIR = .obj >>${APPNAME}.pro
	echo MOC_DIR = .moc >>${APPNAME}.pro
	RMPRO=yes
fi

####################################################################################
#	if to do tmake
####################################################################################
if [[ ( ${DOTMAKE} != "" ) && ( ${DOTMAKE} != "yes" ) ]]; then
	# some apps use specific Makefile, use specific Makefile, so don't execute tmake, and don't remove it after make
	RMMAKE=no
else
	# apps use tmake to generate Makefile, remove it after make
	tmake ${APPNAME}.pro -o Makefile
	RMMAKE=yes
fi

####################################################################################
#	make for project
####################################################################################
make -j20

####################################################################################
#	move and link for target
####################################################################################
#mkdir -p ${TARGETDIR}
#cp -f ${APPNAME} ${TARGETDIR}
#ln -sf ${TARGETDIR}/${APPNAME} ${TARGETDIR}/${APPNAME}.elf

####################################################################################
#	clean project
####################################################################################
if [[ ( ${DOCLEAN} != "" ) && ( ${DOCLEAN} != "yes" ) ]]; then
	echo 
else
	make clean -s
fi
#if [[ ( ${RMPRO} = "" ) || ( ${RMPRO} = "yes" ) ]]; then
#	# remove ${APPNAME}.pro that progen generated or useless
#	rm -f ${APPNAME}.pro
#fi
#if [[ ( ${RMMAKE} = "" ) || ( ${RMMAKE} = "yes" ) ]]; then
#	# remove Makefile that tmake generated or useless
#	rm -f Makefile
#fi

echo -------------------------------------------------------------------------------
