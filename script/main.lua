
local main = {}

local task = require "task.init"

function OnMessage1( cmd , ...)

	print "this is main OnMessage"

end



local comm = require "comm"
function main.test_func()

	print(comm.MyAdd())
	task.inittask("check task init")

end

main.playerData = main.playerData or {}

table.insert(main.playerData,1111)

table.insert(main.playerData,1111)

main.playerData.id=1001
main.playerData.name="luors"
main.playerData.itembag = {}
main.playerData.herobag = {}

print ("main.playerData len="..#(main.playerData))

for k,v in pairs(main.playerData) do
	print(k,v);
end


return main

