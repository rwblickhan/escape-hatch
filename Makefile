CC=g++
CFLAGS=-std=c++11 -c -Wall -Isrc/inc
LFLAGS=-std=c++11 -Wall -Isrc/inc
ALLLIB=\
	   GameManager.o		 \
	   InputHandler.o		 \
	   InventoryInterface.o  \
	   Item.o				 \
	   NavigationInterface.o \
	   Stage.o 

out: $(ALLLIB)
	$(CC) $(LFLAGS) -o eh.out src/main.cpp $(ALLLIB)

GameManager.o: src/GameManager.cpp
	$(CC) $(CFLAGS) src/GameManager.cpp

InputHandler.o: src/InputHandler.cpp
	$(CC) $(CFLAGS) src/InputHandler.cpp

InventoryInterface.o: src/InventoryInterface.cpp
	$(CC) $(CFLAGS) src/InventoryInterface.cpp

Item.o: src/Item.cpp
	$(CC) $(CFLAGS) src/Item.cpp

NavigationInterface.o: src/NavigationInterface.cpp
	$(CC) $(CFLAGS) src/NavigationInterface.cpp

Stage.o: src/Stage.cpp
	$(CC) $(CFLAGS) src/Stage.cpp

clean:
	rm *.o && rm eh.out
