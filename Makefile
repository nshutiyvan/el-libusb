#Xbox controller compiler
#
#
#Author:Nshuti Yvan CHristian

.PHONY:clean
rasp:main.c
	arm-linux-gcc main.c -o appRas -lusb-1.0
	@echo Done making target code
app:main.c
	gcc main.c -o app -lusb-1.0
	@echo Done making host code
send:appRas
	scp appRas root@10.0.0.42:/root
	ssh root@10.0.0.42		
clean:
	rm -rf main.o app appRas
	@echo Done cleaning up