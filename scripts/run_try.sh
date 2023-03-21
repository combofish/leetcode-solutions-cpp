#!/bin/env zsh
# author:combofish
# email:combofish49@gmail.com 
# Filename: run.sh

filename="try_"$1

echo "zsh| Processing $filename"
echo ""

DIR="./run"
if [ ! -d "$DIR" ];then
   mkdir "$DIR"
   echo "create dir: $DIR"
fi
   
   # compile and run and del
   #    g++ --std=c++2a -g -Wall
   clang++ -fsanitize=address -O1 -fno-omit-frame-pointer -g \
	   "./src/${filename}.cpp" -o ./run/$filename \
       && ./run/$filename \
       && rm ./run/$filename \

