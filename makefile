PREFIX = /usr/local/bin

chat: main.cpp lib
	g++ -std=c++17 -o chat main.cpp -L. -lChat

lib: Message.h User.h User.cpp Chat.h Chat.cpp Interface.h Interface.cpp
	g++ -std=c++17 -o UserLib.o User.cpp -c
	g++ -std=c++17 -o ChatLib.o Chat.cpp -c
	g++ -std=c++17 -o InterfLib.o Interface.cpp -c
	ar rc libChat.a UserLib.o ChatLib.o InterfLib.o

clean:
	rm *.o *.a

install:
	install ./chat $(PREFIX)

uninstal:
	rm -rf $(PREFIX)/chat
