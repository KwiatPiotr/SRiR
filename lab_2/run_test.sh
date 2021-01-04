for i in {1..20}
do
	./matrix_32_0 1000 1000 1000 $i >> res_32_0
	echo 32_0
	./matrix_32_3 1000 1000 1000 $i >> res_32_3
	echo 32_3
	./matrix_64_0 1000 1000 1000 $i >> res_64_0
	echo 64_0
	./matrix_64_3 1000 1000 1000 $i >> res_64_3
	echo 64_3
	echo "ended " $j " for threads " $i 
done
