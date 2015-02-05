Precord Pstruct out_sum_data_line_t {
  Pa_uint32             order_item;           '|';
  Pomit Pa_uint32       vbars;                '|';
  Pa_uint32             create_id : create_id == vbars;
};
