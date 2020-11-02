
#include <iostream>
#include <string>
#include <memory>
using namespace std;

#include "lua.hpp"

class A{
public:
	A():mStr("aa"){
		std::cout << "this is A constutor" << mStr << endl;
	}
	~A(){

		std::cout << "this is A disconstrutor" << endl;
	};
private:
	string mStr;
};

extern "C" {
	static int 
	MyAdd(lua_State* L)
	{
		std::cout << "aaaaa" << endl;
		shared_ptr<A> p(new A());
		lua_pushinteger(L,111);
		return 1;
	}

	LUAMOD_API int
	luaopen_comm(lua_State *L)
	{
		luaL_Reg l[] = {
			{"MyAdd",MyAdd},
			{NULL,NULL},
		};

		luaL_newlib(L,l);
		return 1;
	}

}
