
package.path = package.path .. ";" .."./script/?.lua"

local main = require "main"
local task = require "task.init"


main.test_func()
task.inittask("check task init when entry")

function OnMessage( cmd , ...)

	print(cmd,...)

end




