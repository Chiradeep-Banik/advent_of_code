#!/usr/bin/sh


echo "Enter day number : "
read day


curl -s "https://adventofcode.com/2023/day/${day}/input" \
    --cookie "session=53616c7465645f5ffa87f9ebd9fd539ef7278f4049dccd2ee5889ce7948dfc774007f1662b91c1d82d28dd7eaa574a89c7f6f2b266b0077b91acc8525cff0e23" \
    -o "${day}_input.txt"