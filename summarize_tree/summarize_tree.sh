#!/usr/bin/env bash

HERE=$(pwd) #gets current position

PATH="$1" #sets input to $PATH

cd "$PATH" || exit #cds into the called path

NUM_OF_FILES=$( find . -type f | wc -l)

NUM_OF_DIRS=$( find . -type d | wc -l)

echo "There were" "$NUM_OF_DIRS" "directories."
echo "There were" "$NUM_OF_FILES" "regular files."

cd "$HERE" || exit
