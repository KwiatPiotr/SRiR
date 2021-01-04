gcc CW03_pi.c -fopenmp

echo Compiled

for i in {1..16}
do
	./a.out $i
	echo Done $i
done



