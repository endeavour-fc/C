module top(rst,clk,rw,rs,en,data,key1,key2,key3,keyen,led,beep,sys_rst_n,dq,sel,seg_led);
input clk,rst;
input key1,key2,key3,keyen;
output rs,en,rw;
output [7:0] data;
output [7:0]led; 
output beep;			//蜂鸣器输出端
reg [15:0] beep_count = 16'h0;		//蜂鸣器寄存器
reg [15:0] beep_count_end = 16'hffff; //蜂鸣器截止寄存器
input sys_rst_n   ;   //输入的复位信号
inout dq         ;    //ds18b20温度传感器单总线
output  [5:0]    sel        ;   //输出数码管位选信号
output  [7:0]    seg_led     ;     //输出数码管段选信号                          
//                 
wire nao_signal;
reg key1_out,key2_out,key3_out;
temp_disp U2(.sys_clk(clk), .sys_rst_n(sys_rst_n), .dq(dq), .sel(sel), .seg_led(seg_led));
date U1(.clk(clk), .rst(rst),.rs(rs),.en(en),.rw(rw),.data(data),.key1(key1_out),.key2(key2_out),.key3(key3_out),.keyen(keyen),.led(led),.beep(beep));
//clock_alarm U2(.clk_sec(clk_sec),.rst(rst),.shi(shi),.fen(fen),.alarm_shi(alarm_shi),.alarm_fen(alarm_fen),.led(led));
//fp U3(.clk(clk),.rst(rst),.clk_sec(clk_sec));
wire clk,rst;
wire rs,en,rw;
wire [7:0] data;


//按键消抖
reg key1_reg1,key1_reg2;
reg key2_reg1,key2_reg2;
reg key3_reg1,key3_reg2;
reg [31:0] count;
always @(posedge clk)//20ms
begin
	count<=count+1;
	if(count==500_000)
	begin
		count<=0;
		key1_reg1<=key1;
		key2_reg1<=key2;
		key3_reg1<=key3;
	end
	key1_reg2<=key1_reg1;
	key2_reg2<=key2_reg1;
	key3_reg2<=key3_reg1;
	
	key1_out <= key1_reg2 & (!key1_reg1);
	key2_out <= key2_reg2 & (!key2_reg1);
	key3_out <= key3_reg2 & (!key3_reg1);
end

endmodule

