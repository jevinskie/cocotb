module dummy_module (
    input i,
    output reg o
    );

  always @(i) begin
    o = ~i;
  end

endmodule
