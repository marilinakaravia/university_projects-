library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_dff_a is
end tb_dff_a;

architecture tb_behavioral of tb_dff_a is
    signal clk, rst, d, q : STD_LOGIC := '0';
    
    component dff_a
        Port ( clk : in STD_LOGIC;
               d : in STD_LOGIC;
               rst : in STD_LOGIC;
               q : out STD_LOGIC);
    end component;

begin
    -- Instantiate the D flip-flop
    uut: dff_a
        port map (clk, d, rst, q);

    -- Clock process
    process
    begin
        clk <= '0';
        wait for 5 ns;
        clk <= '1';
        wait for 5 ns;
    end process;

    -- Stimulus process
    process
    begin
        -- Reset
        rst <= '1';
        wait for 10 ns;
        rst <= '0';
        wait for 10 ns;

        -- Set and clear the input
        d <= '1';
        wait for 10 ns;
        d <= '0';
        wait for 10 ns;

        -- Test with the clock rising edge
        d <= '1';
        wait for 5 ns;
        d <= '0';
        wait for 5 ns;

        -- Test with the clock falling edge
        d <= '1';
        wait for 5 ns;
        d <= '0';
        wait for 5 ns;

        -- Reset again
        rst <= '1';
        wait for 10 ns;
        rst <= '0';
        wait for 10 ns;

        -- Test with the clock rising edge
        d <= '1';
        wait for 5 ns;
        d <= '0';
        wait for 5 ns;

        -- Test with the clock falling edge
        d <= '1';
        wait for 5 ns;
        d <= '0';
        wait for 5 ns;

        -- Add more test cases as needed

        wait;
    end process;

end tb_behavioral;


