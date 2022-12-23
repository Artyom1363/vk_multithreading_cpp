#!/usr/bin/env bash

set -x
# if something will be wrong, exception shell stops
# set -e

path="./tmp/check"
output=$($path 1 "test/data/test_data1.txt")
if [[ $output == "YES" ]]; then
	echo "OK"
else
	echo "FAILED"
fi

output=$($path 2 "test/data/test_data2.txt")
if [[ $output == "Length of equal part is: 2" ]]; then
	echo "OK"
else
	echo "FAILED"
fi