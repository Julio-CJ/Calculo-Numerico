all: clean metodos
metodos:
	@echo " "
	@echo "==============================="
	@echo "|           METODOS           |"
	@echo "==============================="
	@echo "Compilando os metodos. Programa metodos"
	gcc Metodos.h Metodos.c main.c -o metodos
	chmod +x metodos
clean:
	@echo " "
	@echo "==============================="
	@echo "|    REMOVENDO PROGRAMAS      |"
	@echo "==============================="
	@echo "Removendo os arquivos compilados"
	rm -f metodos