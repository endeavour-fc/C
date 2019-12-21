module fp(clk,rst,clk_sec);
input clk,rst;
output clk_sec;
reg clk_sec,clk_2hz,clk_4hz;
reg [23:0] counter_clk_sec;
always@(posedge clk)
	begin
		if(!rst)
		begin
			counter_clk_sec<=0;
			clk_sec<=0;
		end
		else
		begin
			if(counter_clk_sec<1249_9999)//0.5s
				counter_clk_sec<=counter_clk_sec+1'b1;
			else
			begin
				clk_sec<=~clk_sec;
				counter_clk_sec<=0;
			end
		end
	end
endmodule
