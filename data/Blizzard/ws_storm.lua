printf = function(s,...)
           return io.write(s:format(...))
         end -- function


         
-- declare our protocol
storm_proto = Proto("storm", "Blizzard Storm Protocol")
-- create a function to dissect it
function storm_proto.dissector(buffer, pinfo, tree)
    if buffer:len() < 16 or buffer(0, 4):uint() ~= 0 then 
        if buffer:len() > 0 then
            local datatree = tree:add(buffer(0), "Data (" .. buffer:len() .. " bytes)")
            datatree:add(buffer(0), tostring(buffer(0)))
        end
        return DESEGMENT_ONE_MORE_SEGMENT 
    end
    
    pinfo.cols.protocol = "STORM"
    local maintree = tree:add(storm_proto, buffer(0, 16), "Blizzard Storm Protocol")
    
    local commandClass
    local commandName
    
    maintree:add(buffer(0, 4), "UDP Type: "   .. buffer(0, 4):le_uint())
    maintree:add(buffer(4, 2), "Checksum: 0x" .. tostring(buffer(4, 2)))
    maintree:add(buffer(6, 2), "Length: "     .. buffer(6, 2):le_uint())
    maintree:add(buffer(8, 2), "Sent: "       .. buffer(8, 2):le_uint())
    maintree:add(buffer(10, 2), "Received: "  .. buffer(10, 2):le_uint())
    
    commandClass = buffer(12, 1):le_uint()
    if     (commandClass == 0) then commandName = "SNet_Main"
    elseif (commandClass == 1) then commandName = "SNet_Message"
    elseif (commandClass == 2) then commandName = "SNet_Turns"
    elseif (commandClass == 3) then commandName = "SNet_Unknown"
    else                            commandName = "SNet_Invalid"
    end
    
    pinfo.cols.info = commandName
    
    maintree:add(buffer(12, 1), "Command Class: " .. commandClass .. " [" .. commandName .. "]")
    maintree:add(buffer(13, 1), "Command ID: "    .. buffer(13, 1):le_uint())
    maintree:add(buffer(14, 1), "Player ID: "     .. buffer(14, 1):le_uint())
    maintree:add(buffer(15, 1), "Flags: "         .. buffer(15, 1):le_uint())
    if buffer:len() > 16 then
        local datatree = tree:add(buffer(16), "Data (" .. (buffer:len() - 16) .. " bytes)")
        datatree:add(buffer(16), tostring(buffer(16)))
    end
end
-- load the udp.port table
udp_table = DissectorTable.get("udp.port")
udp_table:add(6112, storm_proto)