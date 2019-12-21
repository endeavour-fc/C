library verilog;
use verilog.vl_types.all;
entity top_vlg_check_tst is
    port(
        beep            : in     vl_logic;
        data            : in     vl_logic_vector(7 downto 0);
        dq              : in     vl_logic;
        en              : in     vl_logic;
        led             : in     vl_logic_vector(7 downto 0);
        rs              : in     vl_logic;
        rw              : in     vl_logic;
        seg_led         : in     vl_logic_vector(7 downto 0);
        sel             : in     vl_logic_vector(5 downto 0);
        sampler_rx      : in     vl_logic
    );
end top_vlg_check_tst;
