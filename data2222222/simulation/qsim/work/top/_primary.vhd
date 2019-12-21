library verilog;
use verilog.vl_types.all;
entity top is
    port(
        rst             : in     vl_logic;
        clk             : in     vl_logic;
        rw              : out    vl_logic;
        rs              : out    vl_logic;
        en              : out    vl_logic;
        data            : out    vl_logic_vector(7 downto 0);
        key1            : in     vl_logic;
        key2            : in     vl_logic;
        key3            : in     vl_logic;
        keyen           : in     vl_logic;
        led             : out    vl_logic_vector(7 downto 0);
        beep            : out    vl_logic;
        sys_rst_n       : in     vl_logic;
        dq              : inout  vl_logic;
        sel             : out    vl_logic_vector(5 downto 0);
        seg_led         : out    vl_logic_vector(7 downto 0)
    );
end top;
