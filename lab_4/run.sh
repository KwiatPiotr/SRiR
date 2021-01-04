#/bin/bash
for j in {1..3}
do
	for i in  1 4 8 16 
	do
		mpiexec -n $i ./CW04_$j.out
		echo Done $j $i
	done
done



