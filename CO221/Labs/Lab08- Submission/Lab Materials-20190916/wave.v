// CO221 - Digital Design - 2019
// Generation of a wave form using GTKWave

module wave;

	reg x;
	reg y;	

	// Initial block runs only once, starting at time 0
	initial
	begin
		//generate files needed to plot the waveform
		//you can plot the waveform generated after running the simulator by using gtkwave
		$dumpfile("wavedata.vcd"); 
		$dumpvars(0,wave); 
		
		x = 0;
		y = 0;
		
		#400 $finish;
	end
	
	// Always block runs in a loop, starting at time 0
	always
	begin
		#20; // Delay of 20 time units
		x = 1;
		#20;
		x = 0;			
	end
		
	// Always block runs in a loop, starting at time 0
	always
	begin
		#15;
		y = 1;
		#15;
		y = 0;
	end
		
	
		
endmodule
