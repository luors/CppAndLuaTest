
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <memory>
#include "lua.hpp"

using namespace std;

class LuaVMObject{
private:

	lua_State *m_LuaState;
	string m_entyfile;
	bool _isLoaded;
	bool loadfile(const char* file=nullptr){
		const char* luafile;
		if (m_entyfile.size() > 0)
			luafile = m_entyfile.c_str();
		else
			luafile = (file!=nullptr)?file:"entry.lua";
		int ret = luaL_loadfile(m_LuaState,luafile);
		if (ret){
			std::cout << "load entry file error" << ret << endl;
			return false;
		}
		ret = lua_pcall(m_LuaState,0,0,0);
		if(ret){
			std::cout << "ERROR:" << lua_tostring(m_LuaState,-1) << endl;
			return false;
		}
		return true;
	}

	LuaVMObject& operator = (LuaVMObject& other) = delete;
	LuaVMObject(LuaVMObject&) = delete;

public:

	lua_State* getVM() const { return m_LuaState;}

	LuaVMObject ():\
	m_LuaState(luaL_newstate()),\
	m_entyfile(""){
		
		luaL_openlibs(m_LuaState);
		loadfile();

	}

	LuaVMObject(const char* file):\
	m_LuaState(luaL_newstate()),\
	m_entyfile(""){
		luaL_openlibs(m_LuaState);
		this->loadfile();
	}

	LuaVMObject(const char* file,const char* luapath,const char* cpath):\
	m_LuaState(luaL_newstate()),\
	m_entyfile(""){	
		luaL_openlibs(m_LuaState);
		lua_pushstring(m_LuaState, luapath);
		lua_setglobal(m_LuaState, "LUA_PATH");
		lua_pushstring(m_LuaState, cpath);
		lua_setglobal(m_LuaState, "LUA_CPATH");
		this->loadfile();
	}

	bool OnMessage(const char* buff, unsigned int sz){

		lua_getglobal(m_LuaState, "OnMessage");
		lua_pushstring(m_LuaState, "TEST");
		lua_pushstring(m_LuaState, buff);
		lua_pushinteger(m_LuaState, strlen(buff));
		int iRet = lua_pcall(m_LuaState, 3, 1, 0);
		if (iRet)
		{
			const char* pErrorMsg = lua_tostring(m_LuaState, -1);
			cout << pErrorMsg << endl;
			return false;
		}
		return true;

	}


	~LuaVMObject(){
		std::cout << "~LuaVMObject" <<endl;
		if(m_LuaState!=nullptr){
			std::cout << "close lua VM" <<endl;
			lua_close(m_LuaState);
		}
	}

};

int test2(){

	shared_ptr<LuaVMObject> p(new LuaVMObject());
	string str("hello world");
	p->OnMessage(str.c_str(),str.size());
	str = string("hello world==========");
	p->OnMessage(str.c_str(),str.size());
	return 0;


}

int main(int argc, char* argv[]){

	
	test2();
	std::cout << "test begin" << endl;
	return 0;
}


