#Xbox controller compiler
#
#
#Author:Nshuti Yvan CHristian

.PHONY:clean

appRas:appRas.o
	arm-linux-gcc -o appRas appRas.o -lusb-1.0
	@echo Done compiling for target	
appRas.o:main.c
	arm-linux-gcc -c -o appRas.o main.c
	@echo Done making object file code		
app.o:main.c
	gcc -c -o app.o  main.c  
	@echo Done making host object file code

send:appRas
	scp appRas root@10.0.0.42:/root
	ssh root@10.0.0.42		
clean:
	rm -rf appRas.o app appRas
	@echo Done cleaning up