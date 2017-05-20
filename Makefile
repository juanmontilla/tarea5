# Makefile pines

CC	= arm-linux-gnueabihf-g++-4.9
CFLAGS  = -c -Wall
SRCS    = $(wildcard *.cpp)     #busca todos los .cpp y guarda todo en la variable
OBJS	= $(subst .cpp,.o,$(SRCS)) #susttuye.cpp por .o
TARGET  = prueba

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)   

%.o:%.cpp
	$(CC) $(CFLAGS) $< -o $@

upload: $(TARGET)
	scp $^ debian@192.168.7.2:~/Desktop/tarea5 #beagle
#	scp $^ pi@192.168.1.50:/home/pi/Desktop    #raspberry
clean:
	rm -f $(TARGET) *.o 
