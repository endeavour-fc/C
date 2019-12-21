library verilog;
use verilog.vl_types.all;
entity top_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        dq              : in     vl_logic;
        key1            : in     vl_logic;
        key2            : in     vl_logic;
        key3            : in     vl_logic;
        keyen           : in     vl_logic;
        rst             : in     vl_logic;
        sys_rst_n       : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end top_vlg_sample_tst;
