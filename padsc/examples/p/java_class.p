/*
 * PADS description of the Java .class file format.
 * Joel Jones (joelkevinjones@gmail.com), 2007
 */

Ptypedef Psbh_uint8(:1:) u1;
Ptypedef Psbh_uint16(:2:) u2;
Ptypedef Psbh_uint32(:4:) u4;

Pstruct CONSTANT_Class_info {
    u1 tag : tag == 7;
    u2 name_index;
};

Pstruct CONSTANT_Fieldref_info {
    u1 tag : tag == 9;
    u2 class_index;
    u2 name_and_type_index;
};

Pstruct CONSTANT_Methodref_info {
    u1 tag: tag == 10;
    u2 class_index;
    u2 name_and_type_index;
};

Pstruct CONSTANT_InterfaceMethodref_info {
    u1 tag: tag == 11;
    u2 class_index;
    u2 name_and_type_index;
};

Pstruct CONSTANT_String_info {
    u1 tag: tag == 8;
    u2 string_index;
};

Pstruct CONSTANT_Integer_info {
    u1 tag: tag == 3;
    u4 bytes;
};

Pstruct CONSTANT_Float_info {
    u1 tag: tag == 4;
    u4 bytes;
};

Pstruct CONSTANT_Long_info {
    u1 tag: tag == 5;
    u4 high_bytes;
    u4 low_bytes;
};

Pstruct CONSTANT_Double_info {
    u1 tag: tag == 6;
    u4 high_bytes;
    u4 low_bytes;
};

Pstruct CONSTANT_NameAndType_info {
    u1 tag: tag == 12;
    u2 name_index;
    u2 descriptor_index;
};

Pstruct CONSTANT_Utf8_info {
    u1 tag: tag == 1;
    u2 length;
    u1[length] bytes;
};

Punion cp_info {
	CONSTANT_Class_info class_info;
	CONSTANT_Fieldref_info fieldref_info;
	CONSTANT_Methodref_info methodref_info;
	CONSTANT_InterfaceMethodref_info interfaceMethodref_info;
	CONSTANT_String_info string_info;
	CONSTANT_Integer_info integer_info;
	CONSTANT_Float_info float_info;
	CONSTANT_Long_info long_info;
	CONSTANT_Double_info double_info;
	CONSTANT_NameAndType_info nameAndType_info;
	CONSTANT_Utf8_info utf8_info;
};

Parray cp_info_arr (: u2 count :) { cp_info[count]; };

/* TO DO enter all the different type of attribute fields, like Code, 
 * Exceptions, InnerClasses, Synthetic, SourceFile, LineNumberTable,
 * LocalVariableTable, Deprecated */

/* could this be done by passing in the constant_pool to the method_info
 * and to the attribute_info? 
 * Pstruct code_attribute { no leading tag ... }
 * Punion attribute (: cp_info const_pool, u2 cpIdx :) {
 *   code_attribute code : !strcmp("Code", const_pool[cpIdx]);
 * }
 * Pstruct attribute_info (const_pool) { 
 *   u2 attribute_name_index; 
 *   attribute(const_pool, attribute_name_index) body;
 * }
 *   OR
 */

Pstruct exception_table_info {
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
}

Pstruct generic_attribute_info {
  u2 attribute_name_index;
  u4 attribute_length;
  u1[attribute_length] info;
}

Pstruct code_attribute (: cp_info_arr const_pool :) {
  u2 attribute_name_index ;
//    : !strcmp("Code", const_pool[attribute_name_index]);
  u4 attribute_length;
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1[code_length] code;
  u2 exception_table_length;
  exception_table_info[exception_table_length] exception_table;
  u2 attributes_count;
  generic_attribute_info[attributes_count] attributes;
}

Punion attribute_info (: cp_info_arr const_pool :) {
  code_attribute(:const_pool:) code;
  generic_attribute_info generic_attribute;
}

Pstruct field_info (: cp_info_arr const_pool :) {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info(:const_pool:)[attributes_count] attributes;
};

Pstruct method_info (: cp_info_arr const_pool :) {
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    attribute_info(: const_pool :)[attributes_count] attributes;
};



Pstruct ClassFile {
    u4 magic : magic == 0xCAFEBABE;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    cp_info_arr(:constant_pool_count:) constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2[interfaces_count] interfaces;
    u2 fields_count;
    field_info(: constant_pool :)[fields_count] fields;
    u2 methods_count;
    method_info(: constant_pool :)[methods_count] methods;
    u2 attributes_count;
    attribute_info(: constant_pool :)[attributes_count] attributes;
}
