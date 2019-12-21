module seg_led(
    //module clock
    input                   clk    ,        // 时钟信号
    input                   rst_n  ,        // 复位信号

    //seg_led interface
    output   reg  [5:0]     sel    ,        // 动态显示被选中的数码管
    output   reg  [7:0]     seg_led,        // 一个数码管中亮的灯,包含小数点

    //user interface
    input         [19:0]    data   ,        // 6个数码管要显示的数值
    input         [5:0]     point  ,        // 小数点具体显示的位置,从高到低,高电平有效
    input                   en     ,        // 数码管使能信号
    input                   sign            // 符号位（高电平显示“-”号）
);

//parameter define
localparam  MAX_NUM    = 13'd5000  ;        // 1ms计数值
localparam  CLK_DIVIDE =  4'd10    ;        // 时钟分频

//reg define
reg    [12:0]             cnt0     ;        // 1ms计数
reg                       flag     ;        // 1ms计满标志信号
reg    [2:0]              cnt      ;        // 切换显示数码管用
reg    [3:0]              num1     ;        // 送给要显示的数码管，要亮的灯
reg                       point1   ;        // 要显示的小数点
reg    [23:0]             num      ;        // 24位bcd码用寄存器
reg    [ 3:0]             clk_cnt  ;        // 时钟计数
reg                       dri_clk  ;        // 驱动数码管操作的驱动时钟

//wire define
wire   [3:0]              data0    ;        // 十万位数
wire   [3:0]              data1    ;        // 万位数
wire   [3:0]              data2    ;        // 千位数
wire   [3:0]              data3    ;        // 百位数
wire   [3:0]              data4    ;        // 十位数
wire   [3:0]              data5    ;        // 个位数

//*****************************************************
//**                    main code
//*****************************************************

assign  data5 = data / 17'd100000;           // 十万位数
assign  data4 = data / 14'd10000 % 4'd10;    // 万位数
assign  data3 = data / 10'd1000 % 4'd10 ;    // 千位数
assign  data2 = data /  7'd100 % 4'd10  ;    // 百位数
assign  data1 = data /  4'd10 % 4'd10   ;    // 十位数
assign  data0 = data %  4'd10;               // 个位数

//生成数码管的驱动时钟用于驱动数码管的操作
always @(posedge clk or negedge rst_n) begin
   if(!rst_n) begin
       dri_clk <= 1'b1;
       clk_cnt <= 4'd0;
   end
   else if(clk_cnt == CLK_DIVIDE/2 - 1'd1) begin
       clk_cnt <= 4'd0;
       dri_clk <= ~dri_clk;
   end
   else
       clk_cnt <= clk_cnt + 1'b1;
end

//将20位2进制数转换为8421bcd码
always @ (posedge dri_clk or negedge rst_n) begin
    if (!rst_n)
        num <= 24'b0;
    else begin
        if (data5 || point[5]) begin
            num[23:20] <= data5;
            num[19:16] <= data4;
            num[15:12] <= data3;
            num[11:8]  <= data2;
            num[ 7:4]  <= data1;
            num[ 3:0]  <= data0;
        end
        else begin
            if (data4 || point[4]) begin
                num[19:0]   <= {data4,data3,data2,data1,data0};
                if(sign)
                    num[23:20] <= 4'd11;
                else
                    num[23:20] <= 4'd10;
            end
            else begin
                if (data3 || point[3]) begin
                    num[15: 0] <= {data3,data2,data1,data0};
                    num[23:20] <= 4'd10;
                    if(sign)
                        num[19:16] <= 4'd11;
                    else
                        num[19:16] <= 4'd10;
                end
                else begin
                    if (data2 || point[2]) begin
                        num[11: 0] <= {data2,data1,data0};
                        num[23:16] <= {2{4'd10}};
                        if(sign)
                            num[15:12] <= 4'd11;
                        else
                            num[15:12] <= 4'd10;
                    end
                    else begin
                        if (data1 || point[1]) begin
                            num[ 7: 0] <= {data1,data0};
                            num[23:12] <= {3{4'd10}};
                            if(sign)
                                num[11:8]  <= 4'd11;
                            else
                                num[11:8] <=  4'd10;
                        end
                        else begin
                            num[3:0] <= data0;
                            if(sign)
                                num[23:4] <= {{4{4'd10}},4'd11};
                            else
                                num[23:4] <= {5{4'd10}};
                        end
                    end
                end
            end
        end
    end
end

//计数1ms
always @ (posedge dri_clk or negedge rst_n) begin
    if (rst_n == 1'b0) begin
        flag <=  1'b0;
        cnt0 <= 13'b0;
     end
    else if (cnt0 < MAX_NUM - 1'b1) begin
        flag <= 1'b0;
        cnt0 <= cnt0 + 1'b1;
     end
    else begin
        flag <=  1'b1;
        cnt0 <= 13'b0;
     end
end

//计数器，用来计数6个状态（因为有6个灯）
always @ (posedge dri_clk or negedge rst_n) begin
    if (rst_n == 1'b0)
        cnt <= 3'b0;
    else if(flag) begin
        if(cnt < 3'd5)
            cnt <= cnt + 1'b1;
        else
            cnt <= 3'b0;
    end
end
//6个数码管轮流显示，完成刷新（ 从右到左）
always @ (posedge dri_clk or negedge rst_n) begin
    if(!rst_n) begin
        sel  <= 6'b000000;
        num1 <= 4'b0;
    end
    else begin
        if(en) begin
            case (cnt)
                3'd0 :begin
                    sel    <= 6'b111110;
                    num1   <= num[3:0] ;
                    point1 <= ~point[0] ;
                end
                3'd1 :begin
                    sel    <= 6'b111101;
                    num1   <= num[7:4] ;
                    point1 <= ~point[1] ;
                end
                3'd2 :begin
                    sel    <= 6'b111011;
                    num1   <= num[11:8];
                    point1 <= ~point[2] ;
                end
                3'd3 :begin
                    sel    <= 6'b110111;
                    num1   <= num[15:12];
                    point1 <= ~point[3]  ;
                end
                3'd4 :begin
                  //  sel    <= 6'b101111;
                   // num1   <= num[19:16];
                   // point1 <= ~point[4];
                end
                3'd5 :begin
                  //  sel    <= 6'b011111;
                   // num1   <= num[23:20];
                   // point1 <= ~point[5];
                end
                default :begin
                    sel    <= 6'b000000;
                    num1   <= 4'b0;
                    point1 <= 1'b1;
                end
            endcase
        end
        else
            sel <= 6'b111111;
    end
end

//数码管显示数据
always @ (posedge dri_clk or negedge rst_n) begin
    if (!rst_n)
        seg_led <= 7'h40;
    else begin
        case (num1)
            4'd0 : seg_led <= {point1,7'b0111111};
            4'd1 : seg_led <= {point1,7'b0000110};
            4'd2 : seg_led <= {point1,7'b1011011};
            4'd3 : seg_led <= {point1,7'b1001111};
            4'd4 : seg_led <= {point1,7'b1100110};
            4'd5 : seg_led <= {point1,7'b1101101};
            4'd6 : seg_led <= {point1,7'b1111101};
            4'd7 : seg_led <= {point1,7'b0000111};
            4'd8 : seg_led <= {point1,7'b1111111};
            4'd9 : seg_led <= {point1,7'b1101111};
            4'd10: seg_led <= 8'b00000000;
            4'd11: seg_led <= 8'b00000000;
            default : seg_led <= {point1,7'b0111111};
        endcase
    end
end

endmodule