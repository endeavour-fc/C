`timescale 10ns/10ns    //100ms=10000*10ns

module time_tb_2;

  //input
reg clk;
reg time_set;
reg rst;             //time_clear--rst; time_set_en--time_set;  
reg[11:0] year_set;  // 12'b1000_0011_0100=2100
reg[3:0] mon_set;  // 4'b1100=12
reg[2:0] week_set; // 3'b111=7
reg[4:0] day_set;  // 5'b1_1111=31
reg[4:0] hour_set;  // 5'b1_1000=24
reg[5:0] min_set;  // 6'b11_1100=60
reg[5:0] sec_set;  // 6'b11_1100=60
  //output
  wire[11:0] year;  // 12'b1000_0011_0100=2100
  wire[3:0] mon;  // 4'b1100=12
  wire[2:0] week; // 3'b111=7
  wire[4:0] day;  // 5'b1_1111=31
  wire[4:0] hour;   // 5'b1_1000=24
  wire[5:0] min;  // 6'b11_1100=60
  wire[5:0] sec;  // 6'b11_1100=60
  wire min_carry,hour_carry,day_carry,mon_carry,year_carry;


  //example 
 time_2  bt(
              clk,
              time_set,
              rst,    //time_clear--rst; time_set_en--time_set;  
              year_set, // 12'b1000_0011_0100=2100
              mon_set,  // 4'b1100=12
              week_set, // 3'b111=7
              day_set,  // 5'b1_1111=31

              hour_set, // 5'b1_1000=24
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

   //testing text;
  initial begin
           clk=0;
           forever #5 clk=~clk; //10 = 1s
          end

  initial
    begin
        time_set=0; //1
        rst=0;
        #1 rst=1;
        #1 rst=0;

        #1000 time_set=1;//2
        #1    time_set=0;

        #1000 time_set=1;//3
        #1    time_set=0;

        #1000 time_set=1;//4
        #1    time_set=0;

        #1000 time_set=1;//5
        #1    time_set=0;

        #1000 time_set=1;//6
        #1    time_set=0;

        #1000 time_set=1;//7
        #1    time_set=0;

        #1000 time_set=1;//8
        #1    time_set=0;

        #1000 time_set=1;//9
        #1    time_set=0;

        #1000 time_set=1;//10
        #1    time_set=0;

        #1000 time_set=1;//11
        #1    time_set=0;

        #1000 time_set=1;//12
        #1    time_set=0;

        #1000 time_set=1;//13
        #1    time_set=0;

        #1000 time_set=1;//14
        #1    time_set=0;

        #1000 time_set=1;//15
        #1    time_set=0;

        #1000 time_set=1;//16
        #1    time_set=0;

        #1000 time_set=1;//17
        #1    time_set=0;

        #1000 time_set=1;//18
        #1    time_set=0;

        #1000 time_set=1;//19
        #1    time_set=0;
    end

   initial
     begin // January
         year_set=2000;  // 12'b1000_0011_0100=2100
         mon_set=1;  // 4'b1100=12
         week_set=1; // 3'b111=7
         day_set=1;  // 5'b1_1111=31
         hour_set=0;    // 5'b1_1000=24
         min_set=0;  // 6'b11_1100=60
         sec_set=0;
        #1000; //February
            year_set=1996;  // 12'b1000_0011_0100=2100
            mon_set=2;  // 4'b1100=12
            week_set=6; // 3'b111=7
            day_set=28;  // 5'b1_1111=31
            hour_set=23;    // 5'b1_1000=24
            min_set=59;  // 6'b11_1100=60
            sec_set=0; 
       #1000; // February
         year_set=2000;  // 12'b1000_0011_0100=2100
         mon_set=2;  // 4'b1100=12
         week_set=1; // 3'b111=7
         day_set=28;  // 5'b1_1111=31
         hour_set=23;   // 5'b1_1000=24
         min_set=59;  // 6'b11_1100=60
         sec_set=0;

       #1000; //February
         year_set=2000;  // 12'b1000_0011_0100=2100
         mon_set=2;  // 4'b1100=12
         week_set=6; // 3'b111=7
         day_set=29;  // 5'b1_1111=31
         hour_set=23;   // 5'b1_1000=24
         min_set=59;  // 6'b11_1100=60
         sec_set=0;
        #1000; //February
          year_set=2004;  // 12'b1000_0011_0100=2100
          mon_set=2;  // 4'b1100=12
          week_set=6; // 3'b111=7
          day_set=28;  // 5'b1_1111=31
          hour_set=23;  // 5'b1_1000=24
          min_set=59;  // 6'b11_1100=60
          sec_set=0; 
         #1000; //February
           year_set=2100;  // 12'b1000_0011_0100=2100
           mon_set=2;  // 4'b1100=12
           week_set=6; // 3'b111=7
           day_set=28;  // 5'b1_1111=31
           hour_set=23; // 5'b1_1000=24
           min_set=59;  // 6'b11_1100=60
           sec_set=0;
         #1000; // February
           year_set=2015;  // 12'b1000_0011_0100=2100
           mon_set=2;  // 4'b1100=12
           week_set=6; // 3'b111=7
           day_set=28;  // 5'b1_1111=31
           hour_set=23; // 5'b1_1000=24
           min_set=59;  // 6'b11_1100=60
           sec_set=0;
       #1000; //March
         year_set=2015;  // 12'b1000_0011_0100=2100
         mon_set=3;  // 4'b1100=12
         week_set=7; // 3'b111=7
         day_set=29;  // 5'b1_1111=31
         hour_set=23;   // 5'b1_1000=24
         min_set=59;  // 6'b11_1100=60
         sec_set=0;
        #1000;  //March
          year_set=2015;  // 12'b1000_0011_0100=2100
          mon_set=3;  // 4'b1100=12
          week_set=1; // 3'b111=7
          day_set=30;  // 5'b1_1111=31
          hour_set=23;  // 5'b1_1000=24
          min_set=59;  // 6'b11_1100=60
          sec_set=0;
         #1000;  //April
           year_set=2015;  // 12'b1000_0011_0100=2100
           mon_set=4;  // 4'b1100=12
           week_set=4; // 3'b111=7
           day_set=30;  // 5'b1_1111=31
           hour_set=23; // 5'b1_1000=24
           min_set=59;  // 6'b11_1100=60
           sec_set=0; 
          #1000;  //May
            year_set=2015;  // 12'b1000_0011_0100=2100
            mon_set=5;  // 4'b1100=12
            week_set=2; // 3'b111=7
            day_set=30;  // 5'b1_1111=31
            hour_set=23;    // 5'b1_1000=24
            min_set=59;  // 6'b11_1100=60
            sec_set=0;
           #1000;  //june
             year_set=2015;  // 12'b1000_0011_0100=2100
             mon_set=6;  // 4'b1100=12
             week_set=2; // 3'b111=7
             day_set=30;  // 5'b1_1111=31
             hour_set=23;   // 5'b1_1000=24
             min_set=59;  // 6'b11_1100=60
             sec_set=0;
            #1000;  //july
              year_set=2015;  // 12'b1000_0011_0100=2100
              mon_set=7;  // 4'b1100=12
              week_set=4; // 3'b111=7
              day_set=30;  // 5'b1_1111=31
              hour_set=23;  // 5'b1_1000=24
              min_set=59;  // 6'b11_1100=60
              sec_set=0;  
           #1000;  //August
             year_set=2015;  // 12'b1000_0011_0100=2100
             mon_set=8;  // 4'b1100=12
             week_set=7; // 3'b111=7
             day_set=30;  // 5'b1_1111=31
             hour_set=23;   // 5'b1_1000=24
             min_set=59;  // 6'b11_1100=60
             sec_set=0;  
            #1000;  //september
              year_set=2015;  // 12'b1000_0011_0100=2100
              mon_set=9;  // 4'b1100=12
              week_set=7; // 3'b111=7
              day_set=30;  // 5'b1_1111=31
              hour_set=23;  // 5'b1_1000=24
              min_set=59;  // 6'b11_1100=60
              sec_set=0; 
            #1000;  //october
              year_set=2015;  // 12'b1000_0011_0100=2100
              mon_set=10;  // 4'b1100=12
              week_set=5; // 3'b111=7
              day_set=30;  // 5'b1_1111=31
              hour_set=21;  // 5'b1_1000=24
              min_set=59;  // 6'b11_1100=60
              sec_set=0; 
             #1000;  //november
               year_set=2015;  // 12'b1000_0011_0100=2100
               mon_set=11;  // 4'b1100=12
               week_set=1; // 3'b111=7
               day_set=30;  // 5'b1_1111=31
               hour_set=23; // 5'b1_1000=24
               min_set=59;  // 6'b11_1100=60
               sec_set=0;
              #1000;  //december
                year_set=2015;  // 12'b1000_0011_0100=2100
                mon_set=12;  // 4'b1100=12
                week_set=4; // 3'b111=7
                day_set=31;  // 5'b1_1111=31
                hour_set=23;    // 5'b1_1000=24
                min_set=59;  // 6'b11_1100=60
                sec_set=0; 
              #1000;  //december
                year_set=2199;  // 12'b1000_0011_0100=2100
                mon_set=12;  // 4'b1100=12
                week_set=6; // 3'b111=7
                day_set=31;  // 5'b1_1111=31
                hour_set=23;    // 5'b1_1000=24
                min_set=59;  // 6'b11_1100=60
                sec_set=0;        
       #1000;
       $stop;
    end

 endmodule
