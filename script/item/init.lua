
--package.path = package.path..";".."./?.lua"


local ITEMLIST = {}


local function require_item_file(fpath)
	local path = string.format("return require \"%s\" ",fpath)
	print("--->",path)
	local f = load(path)
	local t = f()
	for k,v in pairs(t) do print (k,v) end
end

local function load_item_file(fpath)

	local f = loadfile(fpath)
	print("load_item_file1" ,f)
	if f then 
		local x = f()
		for k,v in pairs(x) do print("-->",k,v) end
	end

end



function ITEMLIST.GetItemConf(item_id)
	if ITEMLIST[item_id] then
		return ITEMLIST[item_id].conf
	else
		print "not such item"
	end
	-- body
end

--print(require_item_file("normal.it1001"))

for i =1,4,1 do
load_item_file("script/item/normal/it1001.lua")
end
return ITEMLIST


