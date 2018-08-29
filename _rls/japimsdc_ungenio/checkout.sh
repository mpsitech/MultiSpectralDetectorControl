#!/bin/bash
# file checkout.sh
# checkout script for Msdc Java API library, release japimsdc_ungenio
# author Alexander Wirthmueller
# date created: 29 Aug 2018
# modified: 29 Aug 2018

export set JAVAROOT=/Users/mpsitech/srcjava

mkdir $JAVAROOT/apimsdc
mkdir $JAVAROOT/apimsdc/src
mkdir $JAVAROOT/apimsdc/src/apimsdc
mkdir $JAVAROOT/apimsdc/bin
mkdir $JAVAROOT/apimsdc/bin/apimsdc

cp ../../japimsdc/*.java $JAVAROOT/apimsdc/src/apimsdc/

