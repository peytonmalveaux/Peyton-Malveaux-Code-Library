#!/bin/bash

for i in `ls ./data/*.crs`;do
    let count=count+1
done
echo "$count"

