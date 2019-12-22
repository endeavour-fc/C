 `timescale 100ms/100ms
module wan(  clk,
                time_set,
                rst,    //time_clear--rst; time_set_en--time_set;  
                year_set, // 12'b1000_0011_0100=2100
                mon_set,  // 4'b1100=12
                week_set, // 3'b111=7
                day_set,  // 5'b1_1111=31

                hour_set,   // 5'b1_1000=24
                min_set,  // 6'b11_1100=60
                    sec_set,  // 6'b11_1100=60

                    year,                // year[4'h0000], 
                    mon,
                    week,
                    day,

                    hour,
                    min,
                    sec,

                    year_carry,                 // carry define
                    mon_carry,
                    day_carry,
                    hour_carry,            
                    min_carry
                   );

input clk;
input time_set;
input rst;             //time_clear--rst; time_set_en--time_set;  
input[11:0] year_set;  // 12'b1000_0011_0100=2100
input[3:0] mon_set;  // 4'b1100=12
input[2:0] week_set; // 3'b111=7
input[4:0] day_set;  // 5'b1_1111=31
input[4:0] hour_set;    // 5'b1_1000=24
input[5:0] min_set;  // 6'b11_1100=60
input[5:0] sec_set;  // 6'b11_1100=60


output[11:0] year;  // 12'b1000_0011_0100=2100
output[3:0] mon;  // 4'b1100=12
output[2:0] week; // 3'b111=7
output[4:0] day;  // 5'b1_1111=31
output[4:0] hour;   // 5'b1_1000=24
output[5:0] min;  // 6'b11_1100=60
output[5:0] sec;  // 6'b11_1100=60
output min_carry,hour_carry,day_carry,mon_carry,year_carry;


reg[11:0] year;  // 12'b1000_0011_0100=2100
reg[3:0] mon;  // 4'b1100=12
reg[2:0] week; // 3'b111=7
reg[4:0] day;  // 5'b1_1111=31
reg[4:0] hour;  // 5'b1_1000=24
reg[5:0] min;  // 6'b11_1100=60
reg[5:0] sec;  // 6'b11_1100=60
reg min_carry,hour_carry,day_carry,mon_carry,year_carry;         
reg[4:0] date; // 5'b1_1111=31
wire year_4;
wire year_100;
wire year_400;
/*
always@(rst)
  begin  
      year<=2000;     
      mon<=1;    
      week<=6;
      day<=1;
      hour<=0;      
      min<=0;      
      sec<=0;     
  end
  */
  assign year_4=(year[1:0]==2'b0);
  assign year_100=!(year[3:2]==2'b11);
  assign year_400=(year[3:0]==4'b0);

always@(posedge time_set or posedge clk or posedge rst ) //sec
   begin
       if(rst)
             begin    
                 sec<=0;
             end
       else if(time_set)  
             begin
               sec<=sec_set;   
             end
       else if(sec==59)
             begin
               sec<=0;
               min_carry<=1;
             end
       else
             begin
                sec<=sec+1;
                min_carry<=0;
             end

   end

   always@(posedge min_carry or posedge time_set or posedge rst) //min
     begin
       if(rst)
          begin
              min<=0;
          end
       else if(time_set)
          begin
            min<=min_set;
            hour_carry<=0;
          end
       else if(min==59)
            begin
              min<=0;
              hour_carry<=1;
            end   
       else
            begin
                  min<=min+1;
                  hour_carry<=0;
            end
     end

     always@(posedge hour_carry or posedge time_set or posedge rst) //hour
         begin
          if(rst)
             begin
               hour<=0;
             end
          else if(time_set)
             begin
               hour<=hour_set;
               day_carry<=0;    
             end
          else if(hour==23)
             begin
               hour<=0;
               day_carry<=1;
             end
          else 
              begin
                 hour<=hour+1;
                 day_carry<=0;               
              end      
         end    

      always@(posedge day_carry or posedge time_set or posedge rst)   //day
         begin
              if(rst)
                begin
                  day<=1;
                end
              else if(time_set)
                begin 
                  day<=day_set;
                  mon_carry<=0;
                end
              else if(day==date)
                begin
                    day<=1;
                    mon_carry<=1;
                end
              else 
                begin
                    day<=day+1;
                    mon_carry<=0;
                end
         end

     always@(posedge day_carry or posedge time_set or posedge rst) //week
         begin
              if(rst)
                 begin
                     week<=6;
                 end
              else if(time_set)
                 begin
                   week<=week_set;
                 end
              else if(week==7)
                 begin
                   week<=1;
                 end
              else
                  begin
                   week<=week+1;
                  end  
         end        

     always@(posedge mon_carry or posedge time_set or posedge rst) //month
         begin
              if(rst)
                begin
                    mon<=1;
                end
              else if(time_set)
                begin
                  mon<=mon_set;
                  year_carry<=0;
                end
              else if(mon==12)
                 begin
                    mon<=1;
                    year_carry<=1;
                 end
              else
                 begin
                    mon<=mon+1;
                    year_carry<=0;
                 end 
        end

      always@(posedge year_carry or posedge time_set or posedge rst)//year
          begin
           if(rst)
                begin
                    year<=2000;
                end
           else if(time_set)
                begin
                   year<=year_set;
                end
           else if(year==2199)              
              begin
                  year<=2000;        
              end
           else 
              begin
                  year<=year+1;               
              end
        end

   always@(*)
        begin 
          case(mon) 
           1:date=31; 
           2: 
              begin 
                if(((year_4&&!year_400)&&!year_100)||year_400)
                  date=29;
                else
                  date=28;
                end
           3:date=31;
           4:date=30;
           5:date=31; 
           6:date=30;
           7:date=31;
           8:date=31; 
           9:date=30;
           10:date=31;
           11:date=30; 
           12:date=31;
         //  default:date=30; 
         endcase 
       end     

endmodule
