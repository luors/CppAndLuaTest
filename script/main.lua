
local main = {}

local task = require "task.init"


local comm = require "comm"
function main.test_func()

	print(comm.MyAdd())
	task.inittask("check task init")

end


return main

