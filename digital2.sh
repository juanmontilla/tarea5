#SE CONTROLA LOS PINES GPIO DE lA MORA CON EL SISTEMA DE ARCHIVOS
echo 17 > /sys/class/gpio/export	#EXPORTAR PARA CONFIGURAR PIN A UTILIZAR 
cd /sys/class/gpio/gpio17		#ENTRA A LA DIRECCION PIN
echo out > direction  			#PIN COMO PIN DE SALIDA
let i=0
while true;
do
	echo 1 > value  	      	#ESCRIBE EN EL PIN UN HIGH
	sleep 5
	echo 0 > value			#ESCRIBE EN EL PIN UN LOW
	sleep 5
	if i==2;then
		echo 17 > /sys/class/gpio/unexport 	#resetea la configuracion EL PIN
		exit
	fi
	i=i+1
done

#PARA DECLARAR EL PIN COMO ENTRADA:
#	echo in > direction

#PARA LEER EL VALOR DEL PIN DE ENTRADA (RETORNA 1 PARA HIGH Y 0 PARA LOW)
#	cat value
