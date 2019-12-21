module hycd(mclk,led);
input mclk;
output [7:0] led;
reg [7:0] led;
reg [24:0] count;
reg [4:0] state;
wire clk;

always @ (posedge mclk)
count=count+1;
assign clk=count[23];

always @ (posedge clk)
begin
case(state)
5'b00000:	led=8'b11111111;
5'b00001:	led=8'b00000000;
5'b00010:	led=8'b10000000;
5'b00011:	led=8'b11000000;
5'b00100:	led=8'b11100000;
5'b00101:	led=8'b11110000;
5'b00110:	led=8'b11111000;
5'b00111:	led=8'b11111100;
5'b01000:	led=8'b11111110;
5'b01001:	led=8'b11111111;
5'b01010:	led=8'b00000000;
5'b01011:	led=8'b11111111;
5'b01100:	led=8'b00000001;
5'b01101:	led=8'b00000010;
5'b01110:	led=8'b00000100;
5'b01111:	led=8'b00001000;
5'b10000:	led=8'b00010000;
5'b10001:	led=8'b00100000;
5'b10010:	led=8'b01000000;
5'b10011:	led=8'b10000000;
5'b10100:	led=8'b11111111;
5'b10101:	led=8'b00000000;
5'b10110:	led=8'b11111111;
5'b10111:	led=8'b10000001;
5'b11000:	led=8'b11000011;
5'b11001:	led=8'b11100111;
5'b11010:	led=8'b11111111;
5'b11011:	led=8'b00011000;
5'b11100:	led=8'b00111100;
5'b11101:	led=8'b01111110;
5'b11110:	led=8'b11111111;
5'b11111:	led=8'b00000000;
endcase
state=state+1;
end
endmodule 