`timescale 1ns / 1ps

    module alu_testbench;

// Inputs
reg [7:0] A_tb;
reg [7:0] B_tb;
reg [3:0] Opcode_tb;

// Outputs
wire [7:0] Result_tb;
wire Zero_tb;
wire Carry_tb;
wire Overflow_tb;

// Instantiate the Device Under Test (DUT)
// *** YOU MUST CHANGE THIS LINE TO TEST EACH MODEL ***
// alu_behavioral DUT (
// alu_dataflow DUT (
alu_structural DUT(
        .A(A_tb),
        .B(B_tb),
        .Opcode(Opcode_tb),
        .Result(Result_tb),
        .Zero(Zero_tb),
        .Carry(Carry_tb),
        .Overflow(Overflow_tb));

// Test stimulus
initial begin
    // Use $monitor to print whenever a signal changes
    $monitor("Time=%0t | A=0x%h, B=0x%h, Op=%b | Result=0x%h | Flags (Z,C,O)=%b%b%b",
             $time, A_tb, B_tb, Opcode_tb, Result_tb, Zero_tb, Carry_tb, Overflow_tb);

// Test 1: ADD (10 + 5 = 15)
A_tb = 8'd10;
B_tb = 8'd5;
Opcode_tb = 4'b0000;
# 10;

// Test 2: ADD with Carry (200 + 100 = 300 -> 44 with Carry)
A_tb = 8'd200;
B_tb = 8'd100;
Opcode_tb = 4'b0000;
# 10;

// Test 3: ADD with Overflow (100 + 100 = 200 -> -56 in signed)
A_tb = 8'd100;
B_tb = 8'd100;
Opcode_tb = 4'b0000;
# 10;

// Test 4: SUB (10 - 5 = 5)
A_tb = 8'd10;
B_tb = 8'd5;
Opcode_tb = 4'b0001;
# 10;

// Test 5: SUB with Borrow (5 - 10 = -5 -> 251)
A_tb = 8'd5;
B_tb = 8'd10;
Opcode_tb = 4'b0001;
# 10;

// Test 6: SUB for Zero Flag (10 - 10 = 0)
A_tb = 8'd10;
B_tb = 8'd10;
Opcode_tb = 4'b0001;
# 10;

// Test 7: AND (0xAA & 0xF0 = 0xA0)
A_tb = 8'hAA;
B_tb = 8'hF0;
Opcode_tb = 4'b0010;
# 10;

// Test 8: OR (0x0F | 0xF0 = 0xFF)
A_tb = 8'h0F;
B_tb = 8'hF0;
Opcode_tb = 4'b0011;
# 10;

// Test 9: XOR (0xAA ^ 0x55 = 0xFF)
A_tb = 8'hAA;
B_tb = 8'h55;
Opcode_tb = 4'b0100;
# 10;

// Test 10: NOT (~0xAA = 0x55)
A_tb = 8'hAA;
B_tb = 8'b0;
Opcode_tb = 4'b0101;
# 10;

// Test 11: Shift Left (0x01 << 1 = 0x02)
A_tb = 8'h01;
B_tb = 8'b0;
Opcode_tb = 4'b0110;
# 10;

// Test 12: Shift Right (0x80 >> 1 = 0x40)
A_tb = 8'h80;
B_tb = 8'b0;
Opcode_tb = 4'b0111;
# 10;

// Test 13: Relational EQ (5 == 5 -> 1)
A_tb = 8'd5;
B_tb = 8'd5;
Opcode_tb = 4'b1000;
# 10;

// Test 14: Relational EQ (5 == 6 -> 0)
A_tb = 8'd5;
B_tb = 8'd6;
Opcode_tb = 4'b1000;
# 10;

// Test 15: Relational LT (5 < 6 -> 1)
A_tb = 8'd5;
B_tb = 8'd6;
Opcode_tb = 4'b1001;
# 10;

// Test 16: Relational LT (6 < 5 -> 0)
A_tb = 8'd6;
B_tb = 8'd5;
Opcode_tb = 4'b1001;
# 10;

$stop; // End simulation
end

    endmodule