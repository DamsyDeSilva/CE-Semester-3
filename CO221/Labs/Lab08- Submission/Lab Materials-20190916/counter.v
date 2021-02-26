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

