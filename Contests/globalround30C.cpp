// Design Source: up_down_counter.v
// This module implements a 4-bit synchronous up/down counter
// with an asynchronous reset.

module up_down_counter(
    input wire clk,          // Clock input
    input wire rst,          // Asynchronous reset (active high)
    input wire en,           // Enable counting (active high)
    input wire mode,         // Mode: 1 for UP, 0 for DOWN
    output reg [3 : 0] count // 4-bit counter output
);

// This block describes the counter's behavior
always @(posedge clk or posedge rst) begin
    if (rst) begin
    // Reset the counter to 0
    count
    <= 4'b0000;
end else if (en) begin
    // Only count if enabled
    if (mode) begin
        // Mode is 1 (UP): increment the count
        count <= count + 1;
end else begin
        // Mode is 0 (DOWN): decrement the count
        count <= count - 1;
end
    end
        // If not enabled (en=0), the count holds its value
        end

    endmodule