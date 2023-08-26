#!/bin/bash
# 使い方は　./exec.sh {引数の数}
ARGS=$(jot -s " " -r $1 -100 21000000)
echo $ARGS | pbcopy
# ARGS=$((RANDOM%+10000) | head $1)

./push_swap ${ARGS}
echo $ARGS
