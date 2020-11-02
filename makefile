
CC = g++
LUADIR = "../"
SHARED := -fPIC --shared
FLAG =  -g -o0 -std=c++0x -I/home/luors/workspace_new/lua53/src -L/home/luors/workspace_new/lua53/src

a.out:main.cpp comm.so
	$(CC) $(FLAG) -Wl,-E main.cpp  -o a.out  -llua -ldl 

comm.so:commlib.cpp
	$(CC) $(SHARED) $(FLAG)  commlib.cpp -o comm.so

clean:
	rm  *.out *.so













