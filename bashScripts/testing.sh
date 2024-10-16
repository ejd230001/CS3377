#!/usr/bin/bash

i=0

while [ "$i" -lt 5 ]; do
    echo "Hello"
    (( i = i + 1 ))
done
