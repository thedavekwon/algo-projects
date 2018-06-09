#!/usr/bin/env bash

read name

uname=${name^^}

mkdir $uname
cd $uname
cp ../template.cpp "$uname.cpp"
touch "input.txt"