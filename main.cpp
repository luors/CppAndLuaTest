
#include<iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int test(){
	lua_State *L = luaL_newstate();
	if (L == nullptr){
		std::cout << "lua new state error" << endl;
		return 0;
	}
	

	luaL_openlibs(L);
	const char* path = "./?.lua;";
	lua_pushstring(L, path);
	lua_setglobal(L, "LUA_PATH");
	const char* cpath = "./?.so;";
	lua_pushstring(L, cpath);
	int ret = luaL_loadfile(L,"entry.lua");
	if (ret){
		std::cout << "load entry file error" << ret << endl;
		return 0;
	}
	ret = lua_pcall(L,0,0,0);
	if(ret){
		std::cout << "ERROR:" << lua_tostring(L,-1) << endl;
		return 1;
	}

	const char* buff = "hello world";
	lua_getglobal(L, "OnMessage");
	lua_pushstring(L, "TEST");
	lua_pushstring(L, buff);
	lua_pushinteger(L, strlen(buff));
	int iRet = lua_pcall(L, 3, 1, 0);
	if (iRet)
	{
		const char* pErrorMsg = lua_tostring(L, -1);
		cout << pErrorMsg << endl;
		lua_close(L);
		return -1;
	}






	lua_close(L);
	return 0;
}

int main(int argc, char* argv[]){

	
	test();
	std::cout << "test begin" << endl;
	return 0;
}


