#/bin/bash
for j in {1..16}
do
	mpiexec -n $j ./CW04_4.out
	echo Done $j $i
done



