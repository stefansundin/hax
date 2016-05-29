#!/bin/bash
# git bash i windows
for f in *.in
do
	echo "Checking $f.."
	a.exe < "$f" > "${f%.*}.ans2"
	diff "${f%.*}.ans2" "${f%.*}.ans"
	echo
done
