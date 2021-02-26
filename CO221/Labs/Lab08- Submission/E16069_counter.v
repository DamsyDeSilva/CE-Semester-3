// CO221: Digital Design - 2019
// Lab 08: 4-bit Counter implementation in Verilog

// Top level stimulus module
module testbed;

	// Declare variables for stimulating input
	reg clk, clear_bar;
	wire [3:0] counter_out;
	
	// Monitor changes in counter_out and print once a change happens
	initial
		$monitor($time, " Count : %d", counter_out);
		
	// Instantiate the design block counter	
	// counter_out is the 4-bit output from the counter
	// clk is the clock signal
	// The counter should increment at each falling edge of the clock cycle 
	// clear_bar is the signal that asynchronously clears the counter. A clear_bar = 0 should clear the counter
	rippleCounter4 mycounter(counter_out, clk, clear_bar);	
		 	
	initial
	begin
		// Generate files needed to plot the waveform (you can plot the waveform generated after running the simulator by using gtkwave)
		$dumpfile("wavedata.vcd");
		$dumpvars(0, testbed);
		
		// Give initial value for clk input
		clk = 1'b0;
		
		// Reset the counter
		clear_bar = 1'b0;	
		#5 clear_bar = 1'b1;
		#500 clear_bar = 1'b0;
		#50 clear_bar = 1'b1;
	end		

	// Generate the clock input by toggling clk input every 10 time units (clock period = 20 time units)
	always
		#10 clk = ~clk;

	// Finish the simulation after 700 time units
	initial
	begin
		#700 $finish;
	end

endmodule

// your code goes here

//SR latch module

module SR_latch(Q, Qbar, S, R, clear);

    //port declarations
    output Q, Qbar;
    input S, R, clear;
    
    nand n1(Q, S, Qbar);
    nand n2(Qbar, R, Q, clear);

endmodule

//D latch module 

module D_latch(Q, Qbar, D, En, clear);
    
    //Port declarations
    output Q, Qbar;
    input D, En, clear;
    wire s, r;  //outpts of first nand gates
    
    //lowelevel modules
    nand n1(s, D, En);
    nand n2(r, ~D, En);
    
    //SR latch
    SR_latch SR(Q, Qbar, s, r, clear);
    
endmodule

//D_flip flop module
module D_flipflop(Q, Qbar, D, clk,clear);

    //port declarations
    output Q, Qbar;
    input D, clk, clear;
    wire d1, d2;    //outputs of first D-latch
    
    //first D_latch
    D_latch D1(d1, d2, D, clk, clear);
    
    //Second D_latch
    D_latch D2(Q, Qbar, d1, ~clk, clear);
    
endmodule

//T_flipflop module
module T_flipflop(Q, Qbar, T, clk, clear);
    
    //port declaration
    output Q, Qbar;
    input T, clk, clear;
    wire x; //output of the xor
    
    //xor gate
    xor x1(x, T, Q);
    
    //D_flipflop
    D_flipflop DF1(Q, Qbar, x, clk, clear);
    
endmodule

//4bit Ripple Counter module
module rippleCounter4(A, clk, clear);

    //port declaration
    output [3:0] A;  
    input clk, clear;
    wire [3:0] cout;
    
    //T_flipflops
    T_flipflop TF1(A[0], cout[0], 1'b1, clk, clear);
    T_flipflop TF2(A[1], cout[1], 1'b1, A[0], clear);
    T_flipflop TF3(A[2], cout[2], 1'b1, A[1], clear);
    T_flipflop TF4(A[3], cout[3], 1'b1, A[2], clear);
    
endmodule    
    
    
    