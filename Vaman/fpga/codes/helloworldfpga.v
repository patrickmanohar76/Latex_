module logicex (
		input clk ,Q1 , Q2 ,
		output reg D1 , D2
	);
always@ (*) begin
		D1 =((! Q2 ) &&(! Q1 ) );
		D2 = Q1 ;
	end
endmodule
