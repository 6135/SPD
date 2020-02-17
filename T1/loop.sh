#!/bin/bash
a=99999
while [ $a -gt 0 ]; do
	./SequentialFactor A $a
	let a-=1
done



