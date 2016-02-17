#####################################################################
#
#   Process NSX Logs
#   
#   NSX DFW Logs are input in CSV format
#	Jan 27 16:42:13 ORIGINNAME dfwpktlogs: PASS, domain-c100488/1279, IN, 48, TCP, 1.1.1.1, 64208, 2.2.2.2, 7,  S
#
####################################################################



(
	:cmd_name (try)
	:parse_from (last_position)
	## parse each CSV field into 9 fields. 
	:regexp ("dfwpktlogs-- ([^,]+), ([^,]*), ([^,]*), ([^,]+), ([^,]*), ([^,]*), ([^,]*), ([^,]*), ([^,]*),.*") 

	:add_field (
		:type (const)
		:field_name (product)
		:field_type (string_id)
		:field_value ("NSX")
	)
	:add_field (
		:type (index)
		:field_name (Dst)
		:field_type (ipaddr)
                :field_index (8)
	)
	:add_field (
		:type (index)
		:field_name (Src)
		:field_type (ipaddr)
                :field_index (6)
	)
       	:add_field (
                :type (index)
               	:field_name (action)
               	:field_type (action)
                :field_index (1)
              	:dict_name (dfw_action)
        )
       	:add_field (
                :type (index)
               	:field_name (s_port)
               	:field_type (string)
                :field_index (7)
        )
       	:add_field (
                :type (index)
               	:field_name (service)
               	:field_type (string)
                :field_index (9)
        )
       	:add_field (
                :type (index)
               	:field_name (proto)
               	:field_type (protocol)
                :field_index (5)
             	:dict_name (dfw_protocol)
	)
	# This is for debugging, you can print a field in the user/rule: name field to see
 	# what the regex matched
#      	:add_field (
#                :type (index)
#              	:field_name (rule_name)
#              	:field_type (string)
#               :field_index (1)
#       )
#      	:add_field (
#               :type (index)
#              	:field_name (src_user_name)
#              	:field_type (string)
#               :field_index (5)
#       )

)
