module zong(clk,key,dig,seg,beep);    // 模块名 clock 
input clk;         		// 输入时钟 
input [4:0] key;        	//输入按键 
output [7:0] dig;       	// 数码管选择输出引脚 a
output [7:0] seg;       	// 数码管段输出引脚
output beep;			//蜂鸣器输出端
 
reg [7:0] seg_r = 8'h0;        	//定义数码管输出寄存器 
reg [7:0] dig_r;        	//定义数码管选择输出寄存器 
reg [3:0] disp_dat;     	// 定义显示数据寄存器 
reg [8:0] count1;        	//定义计数寄存器
reg [14:0] count;    	//定义计数中间寄存器 

reg [23:0] hour = 24'h235956;        	// 定义现在时刻寄存器 
reg [23:0] clktime = 24'h000000;	//定义设定闹钟
reg [1:0] keyen = 2'b11;        		// 定义标志位  

reg [4:0] dout1 = 5'b11111;
reg [4:0] dout2 = 5'b11111;
reg [4:0] dout3 = 5'b11111;     		// 寄存器  
wire [4:0] key_done;       			// 按键消抖输出 

reg [15:0] beep_count = 16'h0;		//蜂鸣器寄存器
reg [15:0] beep_count_end = 16'hffff; //蜂鸣器截止寄存器

reg clktime_en = 1'b1;			//闹钟使能寄存器
reg sec ;							//1秒时钟
reg clk1;							//1ms时钟
reg beep_r;          				//寄存器 
wire beepen;

assign beep = beep_r;      		//输出音乐 
assign dig = dig_r;        			//输出数码管选择 
assign seg = seg_r;        			//输出数码管译码结果  
assign beepen = |hour[15:4];
assign key_done = key|dout3; // 按键消抖输出 

//1ms信号产生部分 
always @(posedge clk)        			// 定义 clock 上升沿触发  
begin 
	count = count + 1'b1; 
	if(count == 15'd25000)    			//判断0.5ms  
	begin 
	  	count = 15'd0;      		//计数器清零  
		clk1 = ~clk1;       			//置位秒标志  
	end 

end

//秒信号产生部分 
always @(posedge clk1)        			// 定义 clock 上升沿触发  
begin 
	count1 = count1 + 1'b1; 
	if(count1 == 9'd500)    			//判断0.5S 
	begin 
	  	count1 = 9'd0;      			//计数器清零  
		sec = ~sec;       			//置位秒标志  
	end 
end

always @(posedge count1[5]) 		//按键去噪声
begin 
 dout1 <= key; 
 dout2 <= dout1; 
 dout3 <= dout2;   
end 

always @(negedge key_done[4]) 
begin 
  keyen[1] = ~keyen[1];        		//校准按键转换
end

always @(negedge key_done[3]) 
begin 
	keyen[0] = ~keyen[0];        	//定时按键转换
end

 //闹钟定时部分
always @(negedge sec)        			
begin
	if (!keyen[0])									//如果有闹钟设置键按下
	begin
	case(key_done[2:0])
	3'b110:
		begin
	 	clktime[19:16] = clktime[19:16] + 1'b1;			//时个位加一  
			if(clktime[19:16] == 4'ha) 
			begin 
		       clktime[19:16] = 4'h0; 
		 	clktime[23:20] = clktime[23:20] + 1'b1;		//时十位加一 
		  	end 
				if(clktime[23:16] == 8'h24) 
		       	clktime[23:16] = 8'h0; 
		end
	3'b101:
		begin
		clktime[11:8] = clktime[11:8] + 1'b1;			//分个位加一  
			if(clktime[11:8] == 4'ha) 
			begin 
			clktime[11:8] = 4'h0; 
			clktime[15:12] = clktime[15:12] + 1'b1;		//分十位加一
			end
				if(clktime[15:8] == 8'h60) 
				clktime[15:8] = 8'h0; 
		end
	3'b011:
		begin
		clktime[3:0] = clktime[3:0] + 1'b1;				//秒个位加一  
			if(clktime[3:0] == 4'ha) 
			begin 
			clktime[3:0] = 4'h0; 
			clktime[7:4] = clktime[15:12] + 1'b1;		//秒十位加一
			end
				if(clktime[7:0] == 8'h60) 
				clktime[7:0] = 8'h0; 
		end
	default:
		clktime = clktime;
	endcase
	end
end

//数码管显示内容
always @(posedge clk)
begin
	case({keyen[0],count1[3:1]})	 //选择扫描显示数据  
	4'd0:disp_dat = clktime[3:0];		//秒个位  
	4'd1:disp_dat = clktime[7:4];		//秒十位  
	4'd2:disp_dat = 4'ha;				//显示"-" 
	4'd3:disp_dat = clktime[11:8];		//分个位  
	4'd4:disp_dat = clktime[15:12];	//分十位  
	4'd5:disp_dat = 4'ha;				//显示"-" 
	4'd6:disp_dat = clktime[19:16];	//时个位  
	4'd7:disp_dat = clktime[23:20];	//时十位  

	4'd8:disp_dat = hour[3:0];			//秒个位  
	4'd9:disp_dat = hour[7:4];			//秒十位  
	4'd10:disp_dat = 4'ha;				//显示"-" 
	4'd11:disp_dat = hour[11:8];   		//分个位  
	4'd12:disp_dat = hour[15:12];  		//分十位  
	4'd13:disp_dat = 4'ha;				//显示"-" 
	4'd14:disp_dat = hour[19:16];  		//时个位  
	4'd15:disp_dat = hour[23:20];  		//时十位  
	default:disp_dat = 4'ha;			//显示"-" 
	endcase
	
//数码管选择
	case(count1[3:1])      //选择数码管显示位  
	3'd0:dig_r = 8'b11111110;   //选择第一个数码管显示 
	3'd1:dig_r = 8'b11111101;   //选择第二个数码管显示 
	3'd2:dig_r = 8'b11111011;   //选择第三个数码管显示 
	3'd3:dig_r = 8'b11110111;   //选择第四个数码管显示 
	3'd4:dig_r = 8'b11101111;   //选择第五个数码管显示 
	3'd5:dig_r = 8'b11011111;   //选择第六个数码管显示 
	3'd6:dig_r = 8'b10111111;   //选择第七个数码管显示 
	3'd7:dig_r = 8'b01111111;   //选择第八个数码管显示
	endcase
end

//数码管显示
always @(posedge clk) 
begin 
 case(disp_dat) 
  4'h0:seg_r = 8'b00111111;     	//显示 0 
  4'h1:seg_r = 8'b00000110;     		//显示 1 
  4'h2:seg_r = 8'b01011011;     	//显示 2 
  4'h3:seg_r = 8'b01001111;     	//显示 3 
  4'h4:seg_r = 8'b01100110;     	//显示 4 
  4'h5:seg_r = 8'b01101101;     	//显示 5 
  4'h6:seg_r = 8'b01111101;     	//显示 6 
  4'h7:seg_r = 8'b00000111;     		//显示 7 
  4'h8:seg_r = 8'b01111111;     	//显示 8 
  4'h9:seg_r = 8'b01101111;     	//显示 9 
  4'ha:seg_r = 8'b01000000;     		//显示 - 
  default:seg_r = 8'hff;    	//不显示  
 endcase 
 if((count1[3:1]== 3'd2)&sec) 
  seg_r = 8'hff; 
end

 //时间计算及校准部分
always @(negedge sec)//计时处理 
begin
	if(!keyen[1])      //校准键是否有按下  
	begin 
	case(key_done[2:0])
		3'b110:
		begin
	 	hour[19:16] = hour[19:16] + 1'b1;			//时个位加一  
			if(hour[19:16] >= 4'ha) 
			begin 
		       hour[19:16] = 4'h0; 
		 	hour[23:20] = hour[23:20] + 1'b1;		//时十位加一 
		  	end 
				if(hour[23:16] >= 8'h24) 
		       	hour[23:16] = 8'h0; 
		end
		3'b101:
		begin
		hour[11:8] = hour[11:8] + 1'b1;				//分个位加一  
			if(hour[11:8] >= 4'ha) 
			begin 
			hour[11:8] = 4'h0; 
			hour[15:12] = hour[15:12] + 1'b1;		//分十位加一
			end
				if(hour[15:12] >= 4'h6) 
				hour[15:8] = 8'h0; 
		end
		3'b011:
		begin
		hour[3:0] = hour[3:0] + 1'b1;				//秒个位加一  
			if(hour[3:0] >= 4'ha) 
			begin 
			hour[3:0] = 4'h0; 
			hour[7:4] = hour[15:12] + 1'b1;			//秒十位加一
			end
				if(hour[7:4] >= 4'h6) 
				hour[7:0] = 8'h0; 
		end
		default:
		hour = hour;
	endcase
	end 
	else
	begin 
	hour[3:0] = hour[3:0] + 1'b1;  							//秒加 1 
		if(hour[3:0] >= 4'ha) 
		begin 
		hour[3:0] = 4'h0; 
		hour[7:4] = hour[7:4] + 1'b1;  						// 秒的十位加一 
			if(hour[7:4] >= 4'h6) 
			begin 
			hour[7:4] = 4'h0; 
			hour[11:8] = hour[11:8] + 1'b1;					//分个位加一  
				if(hour[11:8] >= 4'ha) 
				begin 
				hour[11:8] = 4'h0; 
				hour[15:12] = hour[15:12] + 1'b1;			//分十位加一  
					if(hour[15:12] >= 4'h6) 
					begin 
					hour[15:12] = 4'h0; 
				 	hour[19:16] = hour[19:16] + 1'b1;		//时个位加一  
						if(hour[19:16] >= 4'ha) 
						begin 
					       hour[19:16] = 4'h0; 
					 	hour[23:20] = hour[23:20] + 1'b1;	//时十位加一 
					  	end 
						if(hour[23:16] >= 8'h24) 
				       	hour[23:16] = 8'h0; 
					end 
				end 
			end 
		end 
	end 
end 

//蜂鸣器的计数定时器
always@(posedge clk) 
begin 
beep_count = beep_count + 1'b1;      						//计数器加 1 
if((beep_count == beep_count_end)&&(!(beep_count_end == 16'hffff))) 
	begin 
	beep_count = 16'h0;       								//计数器清零  
	beep_r = ~beep_r;      								//取反输出信号 
	end 
end 
 
always @(posedge clk) 
begin
if (!beepen)
case(hour[3:0]) 
	4'h0:beep_count_end = 16'h6a88;  				//中音 6 的分频系数值 
	4'h1:beep_count_end = 16'h8637;  				//中音 4 的分频系数值
	4'h2:beep_count_end = 16'h7794;  				//中音 5 的分频系数值  
	4'h3:beep_count_end = 16'hb327;  				//中音 1 的分频系数值 

	4'h5:beep_count_end = 16'hb327;  				//中音 1 的分频系数值 
	4'h6:beep_count_end = 16'h7794;  				//中音 5 的分频系数值 
	4'h7:beep_count_end = 16'h6a88;  				//中音 6 的分频系数值 
	4'h8:beep_count_end = 16'h8637;  				//中音 4 的分频系数值

	default:beep_count_end = 16'hffff; 
endcase
else if (!clktime_en)
begin
	case(count1[8:5])
	4'h0,4'h2,4'h6,4'h8:beep_count_end = 16'h2f74; 		//高音 7 的分频系数值 
		default:beep_count_end = 16'hffff; 
	endcase
end
else
	beep_count_end = 16'hffff;
end

//闹铃使能控制
always @(posedge clk) 
begin
	if (!keyen[0])								//判断闹铃是否有取消
	clktime_en = 1'b1;
	else if ((clktime[23:0] <= hour[23:0])&(clktime[23:0]+10 >=hour[23:0]))
	clktime_en = 1'b0;
end

endmodule 
