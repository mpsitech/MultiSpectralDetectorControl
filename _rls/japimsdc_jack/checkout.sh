#!/bin/bash
# file checkout.sh
# checkout script for Msdc Java API library, release japimsdc_jack
# author Alexander Wirthmueller
# date created: 4 Oct 2018
# modified: 4 Oct 2018

export set JAVAROOT=/home/mpsitech/srcjava

mkdir $JAVAROOT/apimsdc
mkdir $JAVAROOT/apimsdc/src
mkdir $JAVAROOT/apimsdc/src/apimsdc
mkdir $JAVAROOT/apimsdc/bin
mkdir $JAVAROOT/apimsdc/bin/apimsdc

cp ../../japimsdc/*.java $JAVAROOT/apimsdc/src/apimsdc/

