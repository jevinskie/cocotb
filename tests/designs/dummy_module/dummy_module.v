module dummy_module (
    input i,
    input clk,
    output reg o
    );

  always @(i) begin
    o = ~i;
  end

endmodule
