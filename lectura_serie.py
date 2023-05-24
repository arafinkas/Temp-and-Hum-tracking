# mi primer archivo de python despu es de mucho tiempo
import serial
import datetime
import serial.tools.list_ports


#pruebas de calculos temporales
ahora=datetime.datetime.now()
tiempo_ahora=ahora.strftime("%H:%M:%S")
paso=datetime.timedelta(seconds=6)
nueva_hora=ahora+paso

print("Tiempo ahora mismo=",tiempo_ahora)
print("Tiempo despues de 6 segundos",nueva_hora.strftime("%H:%M:%S"))

before=ahora

#devuelve los datos de los puertos serie y escribe el segundo, que corresponde a COM3
portdata=serial.tools.list_ports.comports()
print(portdata[1])

#abre el puerto serie
ser=serial.Serial('COM3',9600,timeout=1)
#if not ser.isOpen():
#    ser.open()

#un contador para estar permanente leyendo del puerto
count=0
while True:
    s=ser.readline()
    s=str(s.replace(b'\n', b' ').replace(b'\r', b' '))
    data=s[2:][:-2]
    if len(data)>0:           #checkea los caracteres del string
        now=datetime.datetime.now()
        deltat=now-before
        deltatime=str(deltat)
        time_now=now.strftime("%H:%M:%S:%f")
        archivo=open("archivoprueba.txt","a")
        archivo.write(time_now+": ,"+deltatime+","+data+"\n")
        archivo.close()
        before=now
        print(data)
        count=count+1
        print("bucle numero: ",count)
    else:
        print("no se han recibido datos")